int system_operate_main(char *cmd, char *buf)
{
        FILE *fp=NULL;
        char  buff[2048]={0};
        int   count=0;
        int   readcount=0;

        if ( (!cmd) || (!buf) ) { 
                return -1;    
        }   
    
        fp=popen(cmd,"r");
        if (fp) {
                readcount=0;
                memset(buff,0,sizeof(buff));
                while( (readcount < sizeof(buff)) && (!feof(fp)) ) { 
                        count=fread(buff+readcount, sizeof(char), sizeof(buff)-readcount, fp);  
                        if ( count >= 0 ) { 
                    readcount +=count;    
                        }   
                }   
                memcpy(buf,buff,strlen(buff));
        } else {
                return -1;    
        }   

        return 0;
}
