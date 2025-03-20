# TCP server. Listens for a connection, receives a string of numbers separated by hyphens, sums the numbers, and sends the result back to the client
# Ethan Greenhouse
# Date: 3/11/2025

import socket

SERVER_ADDRESS = 'localhost'
SERVER_PORT = 12005
SERVER_IDENTIFIER = (SERVER_ADDRESS, SERVER_PORT)
MAX_QUEUE_CONNECTIONS = 5

def main():
    """Main function to run the TCP server."""
    print('Server started.')

    # Create server socket (IPv4, TCP)
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('Server socket created.')

    # Bind the socket to the specified address and port
    server_socket.bind(SERVER_IDENTIFIER)
    print(f'Server socket bound to: {SERVER_IDENTIFIER}')

    # Set the server to listen for incoming connections
    server_socket.listen(MAX_QUEUE_CONNECTIONS)
    print('Server is listening for client connections.')

    # Accept a client connection
    client_socket, client_address = server_socket.accept()
    print(f'Server accepted connection from: {client_address}')

    # Receive message from client
    message_from_client = client_socket.recv(2048)
    print('Server received message from client.')

    # Convert message to string
    string_from_client = message_from_client.decode()
    print(f'Received string: {string_from_client}')

    # Process the received string
    number_strings = string_from_client.split('-')
    numbers = [int(num) for num in number_strings]
    total_sum = sum(numbers)
    print(f'Sum: {total_sum}')

    # Prepare and send the response
    response_string = f'RESULT:{total_sum}'
    response_message = response_string.encode()
    client_socket.send(response_message)
    print('Server sent response to client.')

    # Close connections
    client_socket.close()
    print('Client connection closed.')
    server_socket.close()
    print('Server socket closed.')

    print('Server terminated.')


if __name__ == "__main__":
    main()