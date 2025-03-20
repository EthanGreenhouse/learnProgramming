# Lists unique domain names and extensions given a list of email addresses
# Ethan Greenhouse
# 2/2/2025

def extractDomains(list_of_email_addresses):
    # Check if the input is a list
    if not isinstance(list_of_email_addresses, list):
        return None 

    # List to store unique domain names
    uniqueDomains = []

    # Iterate through each email address in the list
    for email in list_of_email_addresses:
        # Check if the email is a string
        if not isinstance(email, str):
            return None

        # Check if email contains exactly one '@' symbol
        elif email.count('@') == 1:
            # Split local part and domain
            local, domain = email.split('@')

            # Check if the domain contains at least one '.'
            if '.' in domain:
                # Split domain name and extension
                domain_name, extension = domain.rsplit('.', 1)

                # Check if both the domain name and extension contain only alphabetic characters
                if domain_name.isalpha() and extension.isalpha():
                    # Add domain if not alread in the list
                    if domain not in uniqueDomains:
                        uniqueDomains.append(domain)

    # Return a sorted list of unique domain names
    return sorted(uniqueDomains)