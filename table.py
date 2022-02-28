import os


def GetFiles(path: str, fileList: list):
    for root, dirs, files in os.walk(path):
        for dir in dirs:
            GetFiles(dir, fileList)
        for file in files:
            fileList.append(f"{root}/{file}")


def Read2ndLine(file: str) -> str:
    f = open(file, 'r', encoding='utf-8')
    f.readline()
    s = f.readline()
    f.close()
    return s


def GetFinalPath(path: str) -> str:
    li = path.split('/')[-3:]
    return f'{li[0]}/{li[1]}/{li[2]}'


if __name__ == '__main__':

    files = []
    GetFiles('./ds', files)

    dic = {Read2ndLine(item).strip(): item.replace('\\', '/')
           for item in files}

    md = './README.md'
    out = '# DS-SZTU\n\n深圳技术大学数据结构oj答案\n\n|题目|路径|\n|-|-|\n'

    for key in dic:
        tmp = GetFinalPath(dic[key])
        out += f'|{key[6:]}|[{tmp}](https://github.com/Mzying2001/DS-SZTU/blob/main/{tmp})|\n'

    fmd = open(md, 'w', encoding='utf-8')
    fmd.write(out)
    fmd.close()
