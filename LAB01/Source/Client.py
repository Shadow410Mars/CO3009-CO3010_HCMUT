import socket

if __name__ == "__main__":
    host = socket.gethostname()
    port = 22236
    client_socket = socket.socket()
    client_socket.connect((host, port))