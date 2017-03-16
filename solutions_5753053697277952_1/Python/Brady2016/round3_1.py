def cal(inarr):
    letters=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    result=''
    
    for num in range(len(inarr)):
        inarr[num]=int(inarr[num])
    while(1):
        max=0
        order=0
        for num in range(len(inarr)):
            if inarr[num]>max:
                max=inarr[num]
                order=num
        if max==0:
            break
        result=result+letters[order]
        inarr[order]=inarr[order]-1
        max=0
        order=0
        times=0
        for num in range(len(inarr)):
            if inarr[num]>=max:
                max=inarr[num]
                if max==1:
                    times=times+1
                order=num
        if max==0:
            break
        if max==1 and times==2:
            result=result+' '
            continue
        result=result+letters[order]
        inarr[order]=inarr[order]-1
        result=result+' '
    return result

file = open("a")
T = file.readline()
all_the_text=[]

for num in range(1,int(T)+1):
    word=file.readline().strip()
    word=file.readline().strip()
    word=word.split(' ');
    
    final=cal(word)
    temstr='Case #'+str(num)+': '+final+'\n'
    all_the_text.append(temstr)
    
file_object = open('thefile.txt', 'w+')
file_object.writelines(all_the_text)
file_object.close( )





