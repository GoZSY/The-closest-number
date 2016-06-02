/************************************************************************
暴力法计算给出的数中1的个数，然后分别在数的两端进行查找
***************************************************************************/
class CloseNumber {
public:
    vector<int> getCloseNumber(int x) 
    {
        // write code here
        int count = 0;
        vector<int> result;
        if(x<=0)
            return result;
        count = numberOf1(x);
        int big = x+1;
        int small = x-1;
        while(numberOf1(small) != count)
        {
            --small;
        }
        result.push_back(small);
        while(numberOf1(big) != count)
        {
            ++big;
        }
        result.push_back(big);
        return result;
 
    }
private:
	int numberOf1(int x)
    {
        int count = 0;
        while(x)
        {
            count++;
           	x = x&(x-1);
        }
        return count;
    }
};
/*******************************************************************************************
位操作
********************************************************************************************/
 /*思路：获取后一个较大的数
	 * 		1）计算c0和c1。c1是拖尾1的个数，c0是紧邻拖尾1的作坊一连串0的个数。
	 * 		2）将最右边、非拖尾0变为1，其位置为p=c1+c0。
	 * 		3）将位p右边的所有位清零。
	 * 		4）在紧邻位置p的右方，插入c1-1个1。*/
	 public static int getNext(int n){
		int c=n;
		int c0=0;
		int c1=0;
		
		while((c&1)==0&&(c!=0)){
			c0++;
			c>>=1;
		}
		
		while((c&1)==1){
			c1++;
			c>>=1;
		}
		
		if(c0+c1==31||c0+c1==0)//c0+c1+1=32,1表示p所在位。
			return -1;
		
		int p=c0+c1;//最右边处，非拖尾0的位置。
		n|=(1<<p);//翻转0为1
		n&=~((1<<p)-1);//将p右边的所有位清零
		n|=(1<<(c1-1))-1;//在右边填入（c1-1）个1
		
		return n;
	}
	
	/**
	 * 思路：获取前一个较小的数
	 * 		1）计算c0和c1。c1是拖尾1的个数，c0是紧邻拖尾1的作坊一连串0的个数。
	 * 		2）将最右边、非拖尾1变为0，其位置为p=c1+c0。
	 * 		3）将位p右边的所有位清零。
	 * 		4）在紧邻位置p的右方，插入c1+1个1。
	 * 		注意：步骤2和3可以合并。
	 * @param n
	 * @return
	 */
	public static int getPrev(int n){
		int c=n;
		int c0=0;
		int c1=0;
		
		while((c&1)==1){
			c1++;
			c>>=1;
		}
		
		if(c==0)
			return -1;//错误检查！！！全为1时，无法找到
		
		while((c&1)==0&&(c!=0)){
			c0++;
			c>>=1;
		}
		
		int p=c0+c1;
		n&=~((1<<(p+1))-1);//将最右边、非拖尾1变为0，其位置为p=c1+c0;将位p右边的所有位清零。
		int mask=(1<<(c1+1))-1;//在紧邻（！！！）位置p的右方，插入c1+1个1。
		n|=mask<<(c0-1);
		
		return n;
	}
