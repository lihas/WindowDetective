import re
file_name = "src\Window Detective.vcxproj"

lineNum = 0
for line in open(file_name):
    lineNum += 1
    #line = line.strip()
    ctr = 0
    res = re.search(r"""(.*'Debug\|Win32'">.*?\$\()(QtDir)(\).*)\n""",line, re.IGNORECASE)
    res2 = line
    if(res != None):
        ctr += 1
        res2 = re.sub(r"\$\(QTDIR\)",r"$(QTDIRx86)",line, 100, re.IGNORECASE)
        

    res = re.search(r"""(.*'Release\|Win32'">.*?\$\()(QtDir)(\).*)\n""",line, re.IGNORECASE)
    if(res != None):
        ctr += 1
        res2 = re.sub(r"\$\(QTDIR\)",r"$(QTDIRx86)",line, 100, re.IGNORECASE)
        

    res = re.search(r"""(.*'Debug\|x64'">.*?\$\()(QtDir)(\).*)\n""",line, re.IGNORECASE)
    if(res != None):
        ctr += 1
        res2 = re.sub(r"\$\(QTDIR\)",r"$(QTDIRx64)",line, 100, re.IGNORECASE)
        

    res = re.search(r"""(.*'Release\|x64'">.*?\$\()(QtDir)(\).*)\n""",line, re.IGNORECASE)
    if(res != None):
        ctr += 1
        res2 = re.sub(r"\$\(QTDIR\)",r"$(QTDIRx64)",line, 100, re.IGNORECASE)

    if(ctr > 1):
        print(ctr)
        raise Exception("error ctr" )
    print(res2, end=" ")
