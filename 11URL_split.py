# URL SPLIT

from urllib.parse import urlparse
def split_url(url):
    parsed_url = urlparse(url)
    protocol = parsed_url.scheme
    domain = parsed_url.netloc
    path = parsed_url.path
    query = parsed_url.query
    return {
        "Protocol": protocol,
        "Domain": domain,
        "Path": path,
        "Query": query
    }

url = "https://example.com/path/to/resource?id=123&name=abc"
components = split_url(url)

for component, value in components. items():
    print(f" {component}: {value}")
    
    
    