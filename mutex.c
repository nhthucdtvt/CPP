pthread_mutex_t work_mutex;  
 
int x = 0,y = 0,z = 0;  
 
void *thread_A(void *arg) {  
   pthread_mutex_lock(&work_mutex);  
   write x;  
   write y;  
   write x;  
   pthread_mutex_unlock(&work_mutex);  
 }  

 void *thread_A(void *arg) {  
   pthread_mutex_lock(&work_mutex);  
   read x;  
   read y;  
   read x;  
   pthread_mutex_unlock(&work_mutex);  
 }  

 int main() {  
   create thread A;  
   create thread B;  
   return 1;  
 }  