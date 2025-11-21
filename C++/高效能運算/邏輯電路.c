#include <stdio.h>
#define EXTRACT_BIT(n, i) ( ( n & ( 1 << i ) ) ? 1 : 0 )
//檢查第i個位元是否為1，若是回傳1，否則回傳0
int check_circuit(int , int );
int main(){
    int id;
    int z;
    int count;
    
    count = 0;
    
    for (id = 0; id < 65536; id ++)
    {
        z = id;
        if ( check_circuit(id, z) )
            count ++;
    }
    
    printf("Total solutions: %d\n", count);
    
    return 0;
}
int check_circuit(int id, int z)
{
	int v[16];
	int i;
	
	for (i = 0; i < 16; i ++)
		v[i] = EXTRACT_BIT(z, i);
	
	if ( 
	(v[0] || v[1]) && ( !v[1] || !v[3] ) && ( v[2] || v[3] ) &&
	(!v[3] || !v[4]) && (v[4] || !v[5]) &&
	(v[5] || !v[6] ) && (v[5] || v[6]) &&
	(v[6] || !v[15]) && (v[7] || !v[8]) &&
	(!v[7] || !v[13]) && (v[8] || v[9]) &&
	(v[8] || !v[9]) && (!v[9] || !v[10]) &&
	(v[9] || v[11]) && (v[10] || v[11]) &&
	(v[12] || v[13]) && (v[13] || !v[14]) &&
	(v[14] || v[15])
	){
		printf("%d) %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", id,
		v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
		v[9], v[10], v[11], v[12], v[13], v[14], v[15]
		);
		fflush(stdout);
		return 1;
	}
	fflush(stdout);
	return 0;
}