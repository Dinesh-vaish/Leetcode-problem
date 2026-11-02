class Solution:
    def subdomainVisits(self, cpdomains: list[str]) -> list[str]:

        my_dist = {}

        for i in cpdomains:
            count, website = i.split()
            count = int(count)

            parts = website.split(".")

            for j in range(len(parts)):
                subdomain = ".".join(parts[j:])
                my_dist[subdomain] = my_dist.get(subdomain, 0) + count

        return [
            str(count) + " " + domain
            for domain, count in my_dist.items()
        ]