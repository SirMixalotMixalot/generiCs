import sys
class MacroDef:
    def __init__(self,name,args,body):
        self.name = name 
        self.args = args 
        self.body = body.strip() + "\n"
    def expand(self,params):
        body = self.body[:]
        for i,arg in enumerate(self.args):
            body = body.replace(arg,params[i])
        return body
#Too lazy to refactor
def parse_macro_def(line : str) -> MacroDef:

    lparen = line.find("(")
    i = line.find("O") + 1 #macrO
    while line[i].isspace():
        i += 1
    name = line[i:lparen]
    rparen = line.find(")")
    args = []
    i = lparen + 1
    while lparen <= i < rparen:
        arg = ""
        while line[i].isalpha():
            print(line[i])
            arg += line[i]
            i += 1
        print(f"arg {len(args)} = {arg}") # Sanity check
        args.append(arg)
        i += 1

    body = line[rparen + 1:]
    print(name,args,body)
    return MacroDef(name,args,body)
def get_args(func):
    lparen = func.find("(")
    rparen = func.find(")")
    params = func[lparen + 1 : rparen].split(",")
    print(params)
    return [x.strip() for x in params]

def main():
    #file_name = parse_args(sys.argv)
    with open("practice_lib.h","r") as f:
        defs = []
        macs = []
        new_file = []
        lines = f.readlines()
        for l in lines:
            if "//" not in l:
                new_file.append(l)
                continue
            if "//" in l and "MACRO" in l:
                new_file.append(l)
                print(l)
                print("macro def found")
                defs.append(parse_macro_def(l))
                continue
            name = l.lstrip()# //---()
            name = name[name.rfind("/") + 1 : name.find("(")]
            is_comment = False
            for macro in defs:
                if macro.name.strip() == name.strip() :
                    mac = macro.expand(get_args(l))
                    new_file.append(mac)
                else:
                    is_comment = True
            if is_comment:
                new_file.append(l)
        print(new_file)
        #f.write("".join(new_file))
        with open("practice_lib.h","w") as f:
            f.write("".join(new_file))
if __name__ == "__main__":
    main()
