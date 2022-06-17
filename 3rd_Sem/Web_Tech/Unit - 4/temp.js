var http = require("http");
var url = require("url");
var fs = require("fs");
var qs = require("querystring");
var mongoclient = require("mongodb").MongoClient;

http.createServer(function(req,res)
{
	var myurl = url.parse(req.url);
	var pname = myurl.pathname;
	if (pname == '/')
	{
		var fname = "index.html";
	}
	else
	{
		fname = pname.substr(1);
	}
	if (req.method == "GET")
	{
		//http://localhost:8080/get.txt?srn=12345
		var reqobj = qs.parse(myurl.query);
		mongoclient.connect("mongodb://127.0.0.1:27017/",
		{
			useUnifiedTopology:true
		},
		function(err, client)
		{
			if(err) throw err;
			console.log("connected");
			var db = client.db("secB");
			
			db.collection("stud_info").find(reqobj).toArray(function(err, resobjs)
			{
				if(err)
				{
					res.writeHead(500, {"content-type":"text/html"});
					res.write("server error");
					res.end();
				}
				else
				{
					res.writeHead(500, {"content-type":"text/html"});
					res.write(JSON.stringify(resobjs));
					res.end();
				}
			})
		})
	}
	if (req.method == "POST")
	{
		//http://localhost:8080/save.html
		let body = [];
		req.on("data", (chunk)=>
		{
			body.push(chunk);
		})
		req.on("end", ()=>
		{
			var reqdata = Buffer.concat(body).toString();
			var reqobj = JSON.parse(reqdata);
			
			mongoclient.connect("mongodb://127.0.0.1:27017/",
			{
				useUnifiedTopology:true
			},
			function(err, client)
			{
				if(err) throw err;
				console.log("connected");
				var db = client.db("secB");
				
				db.collection("stud_info").insert(reqobj, function(err, resobjs)
				{
					if(err)
					{
						res.writeHead(500, {"content-type":"text/html"});
						res.write("server error");
						res.end();
					}
					else
					{
						res.writeHead(200, {"content-type":"text/html"});
						res.write(JSON.stringify(resobjs));
						res.end();
					}
				})
			})
		})
	}
}).listen(8080);

console.log("server running at http://localhost:8080");
