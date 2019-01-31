
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <string.h>
 
using namespace std;
 
 
//������������·��
#define  TXT_PATH_NAME    "test.txt"
 
void getTxtPartName (char *partName, string txtPathName) ;
 
 
int main()
{
	//ͳ��txt�е�������
	ifstream countSamplesNum(TXT_PATH_NAME);
	string samplesPathName;
 
	int eachSplitGroupLineNum[100];  //������ݵ�����
	int samplesNum = 0;              //txt�е�������
	int splitNum = 0;                //�ƻ���ֵķ���
 
	//ѭ����ȡtxt�ĸ���
	while (1) 
	{
		if (!getline(countSamplesNum,samplesPathName)) 
		{
			break;
		}
		if (samplesPathName.empty()) 
		{
			continue; 
		}
		samplesNum++;
	}
 
	cout<<"����txt����������"<<samplesNum<<endl;
	cout<<"��������������";
	cin>>splitNum;
 
	cout<<endl<<endl<<"����������"<<splitNum<<"�ݵ�������"<<endl;
	for (int i=0; i<splitNum; i++)
	{
		cin>>eachSplitGroupLineNum[i];
	}
	cout<<endl<<endl;
 
	char  dispParams[1024];   //����ԭ�ļ�������
	char saveNameExt[1024];   //�������ļ������֣�Դ�ļ�������
 
	getTxtPartName(dispParams, TXT_PATH_NAME);   //������txt��·����ȡtxt�ļ���
 
 
	//ʵ�ֲ�֣��ļ�����
	ifstream totalSamplesPath(TXT_PATH_NAME);
	string singleSamplesPath;
 
	for (int i=0; i<splitNum; i++)
	{
		sprintf(saveNameExt, "%s_%d.txt", dispParams, i);
		FILE *labelfilename = fopen(saveNameExt, "w+t");
 
		for (int j=0; j<eachSplitGroupLineNum[i]; j++)
		{
			getline(totalSamplesPath, singleSamplesPath);
			const char* ch=singleSamplesPath.c_str();
			if (j==0)
			{
				fprintf(labelfilename, "%s", ch);
			} 
			else 
			{
				fprintf(labelfilename, "\n%s", ch);
			}
		}
 
		fclose(labelfilename);
	}
 
	system("pause");
	return 0;
}
 
 
//��txtPathName��ȡ���һ����\\�����롰.��֮ǰ�Ĳ�������
void getTxtPartName (char *partName, string txtPathName) 
{
	char tmpChar1[1024]={'0',};
	char tmpChar2[1024]={'0',};
	strcpy(tmpChar1, txtPathName.c_str());
	int pathNameLen = strlen(tmpChar1); 
	int pos = pathNameLen; 
	while (pos > 0) 
	{
		pos--; 
		if (tmpChar1[pos] == '\\') 
		{
			pos++; 
			break;
		} 
	}
 
	memcpy(tmpChar2, tmpChar1 + pos, pathNameLen-pos); 
	pos = strlen(tmpChar2); 
 
	while (pos > 0) 
	{
		if (tmpChar2[pos] == '.') 
			break; 
		pos--; 
	}
 
	tmpChar2[pos] = 0; 
	sprintf(partName, "%s", tmpChar2);
}
