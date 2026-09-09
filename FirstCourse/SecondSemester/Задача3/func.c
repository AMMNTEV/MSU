#include "func.h" 

char* main_func(char *line)
{
    int w, len, count, new_len;
    char *temp;

    count = 0;
    len = strlen(line);
    
    for (int i = 0; i < len; i++){
        if(line[i] == ' '){
            count++;
        }
    }
    if (count == 0)
        return line;
    
    new_len = len + count*2;
    
    temp = (char*)realloc(line, new_len + 1);
    if (!temp){
        printf("error");
        return line;
    }
    line = temp;
    
    w = new_len;
    line[w] = '\0';
    w--;
    
    for (int i = len - 1; i >= 0; i--){
        if (line[i] == ' ')
        { 
            line[w--] = '0';
            line[w--] = '2';
            line[w--] = '%';
        }
        else
        {
            line[w--] = line[i];
        }
    }
    
    return line;
}

int str_equal(char *str, char *res)
{
    if (strlen(str) != strlen(res))
    {
        printf("%ld %ld \n", strlen(str) , strlen(res));
        return 0;
    }
    else
    {
        for (size_t i = 0; i < strlen(str); i++)
        {
            if (str[i] != res[i])
            {
                return 0;
            }
        }
    }
    return 1;
}
