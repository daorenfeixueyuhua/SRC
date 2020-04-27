class Logger:

    def __init__(self, file_name):
        self.file_name = file_name

    def _write_log(self, level, msg):
        with open(self.file_name, 'a') as file_log:
            file_log.write("[{0} {1}]".format(level, msg))

    def critical(self, msg):
        self._write_log('CRITICAL', msg)

    def error(self, msg):
        self._write_log('ERROR', msg)

    def warn(self, msg):
        self._write_log('WARN', msg)

    def info(self, msg):
        self._write_log('INFO', msg)

    def debug(self, msg):
        self._write_log('DEBUG', msg)
