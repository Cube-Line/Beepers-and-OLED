Set fs =CreateObject("scripting.filesystemobject")
Set gs =CreateObject("scripting.filesystemobject")
Set f=fs.opentextfile("All.py",1,true) 'Test.txt��Ҫ�ָ��txt�ļ�
n=0
do while f.atendofstream<>true
n=n+1
data=""
Set g=gs.opentextfile(CStr(n)+".py",2, true) '�ָ����ļ�����Ϊ��1.txt 2.txt 3.txt����
if f.atendofstream<>true then
for a=1 to 100000 '�ָ��һ���ļ�����100000�У��հ���ͬ����һ�С�
data=f.readline
g.writeline data
next
end if
loop
f.close
g.close
pause