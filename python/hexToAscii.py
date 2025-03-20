# Converts a hexadecimal string to an ASCII string
# Ethan Greenhouse
# 2/2/2025

def hexToAscii(hex_string):
    # Check if the input is a string
    if not isinstance(hex_string, str):
        
        # Check if the string has an even length
        if len(hex_string) % 2 != 0:
            
            # Check if all characters are valid hexadecimal characters
            if not all(c in '0123456789abcdefABCDEF' for c in hex_string):
                return None
    
    # Convert the hex string to bytes, then decode as ASCII
    return bytes.fromhex(hex_string).decode('ascii')

print(f"ASCII string: {hexToAscii('48656c6c6f')}")  # Output: ASCII string: Hello
