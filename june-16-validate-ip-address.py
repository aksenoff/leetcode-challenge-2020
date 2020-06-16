# https://leetcode.com/problems/validate-ip-address/

class Solution:
    def validIPAddress(self, IP: str) -> str:
        ipv4 = IP.split('.')
        ipv6 = IP.split(':')

        success = True

        if len(ipv4) == 4:
            for part in ipv4:
                if len(part) == 0 or not (part == '0' or part[0] != '0' and part.isdigit() and 0 < int(part) < 256):
                    success = False
                    break
            if success:
                return 'IPv4'

        if len(ipv6) == 8:
            for part in ipv6:
                if len(part) == 0 or not (part == '0' or len(part) <= 4 and all(c in hexdigits for c in part)):
                    success = False
                    break
            if success:
                return 'IPv6'

        return 'Neither'