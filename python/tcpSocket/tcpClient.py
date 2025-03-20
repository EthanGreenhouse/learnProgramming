# TCP client program. Connects to a server, sends a string of numbers, and validates the server's response
# Ethan Greenhouse
# Date: 3/20/2025

import socket

SERVER_ADDRESS = 'localhost'
SERVER_PORT = 12005
SERVER_IDENTIFIER = (SERVER_ADDRESS, SERVER_PORT)
MESSAGE_TO_SEND = '12-23-56-5-95-3-55-24-9-34'
EXPECTED_RESULT = 'RESULT:316'

def main():
    """Main function to run the TCP client."""
    print('Client program started.')

    # Create a TCP socket.
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print('Client socket created.')

    # Connect to the server.
    client_socket.connect(SERVER_IDENTIFIER)
    print('Client socket connected.')

    # Send the message to the server.
    client_socket.send(MESSAGE_TO_SEND.encode())
    print(f'Client sent message to server at: {SERVER_IDENTIFIER}')

    # Receive the response from the server.
    message_from_server = client_socket.recv(2048).decode()
    print(f'Client received: {message_from_server} from server.')

    # Validate the response.
    if message_from_server == EXPECTED_RESULT:
        print("Good job! The answer is correct!")
    else:
        print('Incorrect result received! Please check the server.')

    # Clean up - close the socket.
    client_socket.close()
    print('Client socket closed.')
    print('Client program terminated.')


if __name__ == "__main__":
    main()