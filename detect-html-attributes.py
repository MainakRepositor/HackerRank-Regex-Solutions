import re
from collections import defaultdict

inputs = []
for _ in range(int(input())):
inputs.append(input())

string = ''.join([inp for inp in inputs])

results = re.findall(r'<(\w+)(|\s+[^>]*)>', string, re.I)

tag_attributes = defaultdict(list)
for res in results:
tag, attr = res
tag_attributes[tag].extend(
re.findall(r'(\w+)=['"]', attr)
)

for tag, attr in sorted(tag_attributes.items()):
print(':'.join([tag, ','.join(sorted(set(attr)))]))
