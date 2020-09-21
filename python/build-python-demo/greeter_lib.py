import logging  # https://docs.python.org/3/howto/logging.html#logging-basic-tutorial

def greeter(msg):
    logging.debug('entering greeter(), parameter is: %s', msg)
    print("*****************************************")
    print(msg)
    print("*****************************************")
    logging.debug('exiting greeter()')
