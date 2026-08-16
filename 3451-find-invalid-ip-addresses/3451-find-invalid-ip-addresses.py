import pandas as pd

def find_invalid_ips(logs: pd.DataFrame) -> pd.DataFrame:

    def is_invalid(ip):
        parts = ip.split('.')

        # Less or more than 4 octets
        if len(parts) != 4:
            return True

        for part in parts:

            # Empty / non-numeric octet
            if not part.isdigit():
                return False

            # Leading zero
            if len(part) > 1 and part[0] == '0':
                return True

            # Greater than 255
            if int(part) > 255:
                return True

        return False

    invalid = logs[logs['ip'].apply(is_invalid)]

    return (
        invalid
        .groupby('ip')
        .size()
        .reset_index(name='invalid_count')
        .sort_values(
            ['invalid_count', 'ip'],
            ascending=[False, False]
        )
        .reset_index(drop=True)
    )