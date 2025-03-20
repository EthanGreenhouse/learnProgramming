# Packet Creation and Reception
# Ethan Greenhouse
# 2/2/2025

# Generates packets with data and a parity bit
class PacketGen:
    def initialize(self):
        # Initializes the PacketGen object.
        self.Packet_t = None

    def generatePacket(self, pid, dst, src, data):
        # Generates packet tuple with PID, destination, source, data, and parity bit
        # Checks if the data string
        if not isinstance(data, str):
            print("Error: Data must be a string.")
            return None

        # Converts data to binary
        binary_data = ''.join(format(ord(char), '08b') for char in data)

        # Creates parity bit
        parity_bit = '1' if not binary_data else '0' if binary_data.count('1') % 2 == 0 else '1'

        # Packages packet
        packet = (pid, dst, src, data, parity_bit)
        self.Packet_t = packet
        return packet

# Represents received packet and performs parity checks
class PacketRecv:
    def initialize(self, packet_t):
        # Checks if the packet format is correct
        if not isinstance(packet_t, tuple) or len(packet_t) != 5:
            raise ValueError("Invalid packet format")

        # Sets attributes
        self.pktid = packet_t[0]
        self.dst = packet_t[1]
        self.src = packet_t[2]
        self.data = packet_t[3]
        self.rcvd_parity = packet_t[4]
        self.ParityValid = None

    # Calculates and checks the parity bit against the received parity bit
    def check_parity(self):
        # Converts binary code
        binary_data = ''.join(format(ord(char), '08b') for char in self.data)

        # Gets the computer parity
        computed_parity = '0' if binary_data.count('1') % 2 == 0 else '1'

        # Checks if parity valid
        self.ParityValid = (computed_parity == self.rcvd_parity)

    # Describes parsed packet details and parity check result
    def parsed_packet(self):
        return (f"Packet Number {self.pktid} with message '{self.data}' "
                f"received from node {self.src}.  Parity Check returns {self.ParityValid}")


if __name__ == "__main__":
    # Packet generation
    packetGenerator = PacketGen()
    packet = packetGenerator.generatePacket('1', '192.168.1.100', '192.168.1.1', "Hello")
    # Checks if packet exist
    if packet:
        print(f"Generated Packet: {packet}")

    # Packet processing
    # Check if a packet is valid
    if packet:
        packetReceiver = PacketRecv(packet)
        packetReceiver.check_parity()
        print(packetReceiver.parsed_packet())
