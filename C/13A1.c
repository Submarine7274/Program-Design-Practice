/*Write the following function:

void build_index_url(const char *domain, char *index_url);

domain points to a string containing an Internet domain, such as "knking.corn". 
The function should add "http: //www." to the beginning of this string and "/index.html" to the end of the string, 
storing the result in the string pointed to by index_url.
(In this example, the result will be "http://www.knking.com/index.htm1".) 
You may assume that index_url points to a variable that is long enough to hold the resulting string. 
Keep the function as simple as possible by having it use the strcat and strcopy functions.
*/
#include <stdio.h>
#include <string.h>
void build_index_url(const char *domain, char *index_url);
int main(void){
    char domain[100];
    char index_url[200];
    fgets(domain, sizeof(domain), stdin);
    size_t len= strlen(domain);
    if(domain[len -1] =='\n'){
        domain[len -1] ='\0';
    }
    build_index_url(domain,index_url);
    return 0;
}
void build_index_url(const char *domain, char *index_url){
    strcpy(index_url,"http: //www.");
    strcat(index_url,domain);
    strcat(index_url,"/index.html");
    printf("%s", index_url);
}