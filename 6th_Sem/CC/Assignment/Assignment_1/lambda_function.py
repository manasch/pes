import json
import csv
from base64 import b64decode

def lambda_handler(event, context):
    # TODO implement
    print(event)
    if event['httpMethod'] == 'GET':
        response = event['queryStringParameters']['key']
        return {
            'statusCode': 200,
            'body': json.dumps(f"PES1UG20CS111: {response}")
        }
    elif event['httpMethod'] == 'POST':
        req_body = event['body']
        if not req_body:
            return {
                'statusCode': 200,
                'body': 'No CSV Found'
            }
        else:
            csv_payload = b64decode(event['body']).decode('utf-8')
            lines = csv_payload.split('\n')
            headers = lines[4].strip().split(',')
            data = lines[5:-3]
            values = list(csv.reader(data, delimiter=','))
            
            res = dict()
            for header in headers:
                res[header] = 0
            
            for i in range(len(values)):
                for j in range(len(headers)):
                    res[headers[j]] += int(values[i][j])
            
            for k in res:
                res[k] /= len(values)
            
            return {
                'statusCode': 200,
                'body': json.dumps(res)
            }
    else:
        return {
            'statusCode': 200,
            'body': json.dumps("Only GET and POST are supported")
        }
