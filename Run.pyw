import os
from subprocess import call

os.chdir("Interface")
call(["java", "MyJudge"], shell = True)
