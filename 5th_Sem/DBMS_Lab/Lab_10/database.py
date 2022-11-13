import mysql.connector

mydb = mysql.connector.connect(
    host='localhost',
    user='pes1ug20cs111',
    password='cs111',
    database='pes1ug20cs111_lab10'
)

c = mydb.cursor()

def create_table():
    c.execute(
        "create table if not exists train(\
            train_no int,\
            train_name varchar(20),\
            train_type varchar(10),\
            source varchar(20),\
            destination varchar(20),\
            availability varchar(10)\
        )"
    )

def add_data(train_no, train_name, train_type, source, destination, availability):
    c.execute(f"insert into train values(\
        {train_no},\
        \"{train_name}\",\
        \"{train_type}\",\
        \"{source}\",\
        \"{destination}\",\
        \"{availability}\")")

def view_all_data():
    c.execute("select * from train")
    data = c.fetchall()
    return data

def view_only_train_no():
    c.execute("select train_no from train")
    data = c.fetchall()
    return data

def get_train(train_no):
    c.execute(f"select * from train where train_no = {train_no}")
    data = c.fetchall()
    return data

def edit_train(train_no, train_name, train_type, source, destination, availability):
    c.execute(f"update train set train_name = \"{train_name}\",\
        train_type = \"{train_type}\",\
        source = \"{source}\",\
        destination = \"{destination}\",\
        availability = \"{availability}\"\
        where train_no = {train_no}")
    mydb.commit()
    data = c.fetchall()
    return data

def delete_train(train_no):
    c.execute(f"delete from train where train_no = {train_no}")
    mydb.commit()
