//������δ��װboost�⣬��DiskStorageArea��δ������
//117448696������ͷ����bit��
// 83894264����1bit����32�ֽڵ��������ʼ��
//	2047��838660��25165824��33554432:�ֱ��ʾ����Ϊ8bit��4bit��2bit��1bit������ 
#include <cstdint>
#include<bitset>
#include<malloc.h>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
//#include "AbstractStorageArea.h"
#include "DiskStorageArea.h"
using namespace std;
class BuddyDynamicAllocator
{
protected:
    AbstractStorageArea* storageArea;
public:
    BuddyDynamicAllocator(AbstractStorageArea* storageArea);
    bitset<117448696> *p; 
    const AbstractStorageArea* getStorageArea() const;
    //void initialize();
    uint64_t bytesTotal();//δʵ�֡���TotalĬ��1G�� 
    uint64_t bytesUsed();//δʵ�֡�����allocate���޸ļ��ɣ�Ȼ����֪��Ҫʵ�ֵĹ��� 
    uint64_t bytesAvailable();
    AbstractStorageArea::AccessProxy allocate(uint64_t size);
    bool free(const AbstractStorageArea::AccessProxy& accessProxy);//��֪����δ�accessProxyת�������ļ��е�λ�ã�������free(file_loc,size)ʵ�ּ��� 
    
    uint64_t initialize();
	uint64_t find_son_left(uint64_t father);//loc2loc
	uint64_t find_son_right(uint64_t father);//loc2loc
	uint64_t find_father(uint64_t son);//loc2loc 
	uint64_t find_brother(uint64_t loc);
	uint64_t compute_size(uint64_t loc);//loc2(size-in-pow-type)
	void set_size(uint64_t loc,uint64_t size);
	uint64_t no2loc(uint64_t number);
	uint64_t loc2no(uint64_t location);
	uint64_t loc2file(uint64_t loc);//����λ�õ��ļ��е�λ�� 
	bool free(uint64_t file_loc,uint64_t size);//�ͷ��ļ���λ��file_loc����СΪsize�ĵ�ַ 
	void update_size(uint64_t loc);
	//long long allocate(uint64_t size);//���䵽�ļ���λ�� ���䲻�˷���-1 
	//bool free(uint64_t start,uint64_t size);
};

