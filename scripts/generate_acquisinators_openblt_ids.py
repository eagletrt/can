n=0
id=1

def f(n, id):
    return f'''
    {{
          "name": "ACQUISINATOR_FLASH_{n}_TX",
          "fixed_id": {id},
          "sending": [
            "TLM"
          ],
          "receiving": [
            "ACQUISINATOR"
          ],
          "contents": {{}}
        }},
        {{
          "name": "ACQUISINATOR_FLASH_{n}_RX",
          "fixed_id": {id+1},
          "sending": [
            "TLM"
          ],
          "receiving": [
            "ACQUISINATOR"
          ],
          "contents": {{}}
        }},
    '''

a = open("out.txt", "w+")
for i in range(0, 32):
    a.write(f(n, id))
    n+=1
    id+=2