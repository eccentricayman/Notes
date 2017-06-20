#move this file to .git/hooks
import os
import os.path

files = []

for dirpath, dirnames, filenames in os.walk("../../files"):
    for filename in [f for f in filenames if f.endswith(".md")]:
        files.append(os.path.join(dirpath, filename))

fileLog = open("files.txt", "w")

for filePath in files:
    fileLog.write(filePath + "\n")
