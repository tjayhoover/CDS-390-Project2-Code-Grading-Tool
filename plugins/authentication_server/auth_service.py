import random
import flask
from flask import request, jsonify

app = flask.Flask(__name__)
app.config["DEBUG"] = True

@app.route('/', methods=['POST'])
def gen_token():
    data = request.json
    print(data['permission_level'])
    return {'token': '48yuhv3fn30wij3r23jwi2399uofoi',
            'role': data['permission_level']}

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5000)