import json
from flask import Flask, jsonify 
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/')
def hello_world():

    with open('../CMSC-301-FINAL-PROJECT/webInterfaceOutput.json', 'r') as f:
        json_infile = json.load(f)

    return jsonify(json_infile)



