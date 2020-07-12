from flask import Flask


class Config:
    DEBUG = True


app = Flask(__name__)

app.config.from_object(Config)


@app.route('/')
def hell_world():
    return 'hello, World'


if __name__ == '__main__':
    app.run()
