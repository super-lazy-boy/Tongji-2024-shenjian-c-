/* 2352467 赵阿强 信08 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    if (str == NULL)
        return 0;
    for (; *str != '\0'; str++) {
        count++;
    }
    return count; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* stay = s1;
    if (s1 == NULL || s2 == NULL)
        return s1;
    for (; *s1 != '\0'; s1++)
        ;  
    for (; *s2!='\0'; s2++,s1++) {
            *s1 = *s2;
    }
    *s1 = '\0';
    return stay; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* stay1 = s1;
    const char* stay2 = s2;
    if (s1 == NULL || s2 == NULL)
        return s1;
    for (; *s1 != '\0'; s1++)
        ;
    for (; *s2 != '\0' && s2 - stay2 <len; s2++,s1++) {
        *s1 = *s2;
    }
    *s1 = '\0';
    return stay1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* stay1 = s1;
    if (s1 == NULL)
        return s1;
    if (s2 == NULL) {
        *s1 = '\0';
        return s1;
    }
    for (; *s2 != '\0'; s2++, s1++) {
        *s1 = *s2;
    }
    *s1 = '\0';
    return stay1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* stay1 = s1;
    const char* stay2 = s2;
    if (s1 == NULL||s2 == NULL) {
        return s1;
    }
    for (; *s2 != '\0' && s2 - stay2 < len; s2++, s1++) {
        *s1 = *s2;
    }
    return stay1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* stay1 = s1;
    const char* stay2 = s2;
    int cha = 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++) {
        cha = *s1 - *s2;
        if (cha != 0)
            break;
    }
    return cha;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cha = 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++) {
        if (*s1 <= 'Z' && *s1 >= 'A') {
            if (*s2 <= 'Z' && *s2 >= 'A')
                cha = *s1 + 32 - *s2 - 32;
            else
                cha = *s1 + 32 - *s2;
        }
        else {
            if (*s2 <= 'Z' && *s2 >= 'A')
                cha = *s1 - *s2 - 32;
            else
                cha = *s1 - *s2;
        }
        if (cha != 0)
            break;
    }
    return cha;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* stay1 = s1;
    const char* stay2 = s2;
    int cha = 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    for (; *s1 != '\0' || *s2 != '\0'&&s1-stay1<len; s1++, s2++) {
        cha = *s1 - *s2;
        if (cha != 0)
            break;
    }
    return cha;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* stay1 = s1;
    const char* stay2 = s2;
    int cha = 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    for (; (*s1 != '\0' || *s2 != '\0') && s1 - stay1 < len; s1++, s2++) {
        if (*s1 <= 'Z' && *s1 >= 'A') {
            if (*s2 <= 'Z' && *s2 >= 'A')
                cha = *s1 + 32 - *s2 - 32;
            else
                cha = *s1 + 32 - *s2;
        }
        else {
            if (*s2 <= 'Z' && *s2 >= 'A')
                cha = *s1 - *s2 - 32;
            else
                cha = *s1 - *s2;
        }
        if (cha != 0)
            break;
    }
    return cha;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* stay = str;
    if (str == NULL)
        return str;
    for (; *str!='\0'; str++) {
        if (*str <= 'z' && *str >= 'a')
            *str -= 32;
    }
    return stay;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* stay = str;
    if (str == NULL)
        return str;
    for (; *str != '\0'; str++) {
        if (*str <= 'Z' && *str >= 'A')
            *str += 32;
    }
    return stay;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* stay = str;
    if (str == NULL)
        return 0;
    for (; *str != '\0'; str++) {
        if (*str == ch)
            return str - stay+1;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* stay = str;
    const char* place1 = str;
    const char* place2 = substr;
    int judge = 0;
    if (str == NULL||substr==NULL)
        return 0;
    for (; *str != '\0'; str++) {
        if (*str == *substr) {
            place1 = str;
            for (; *str != '\0' && *substr != '\0'; str++, substr++) {
                if (*str != *substr) {
                    break;
                }
                judge++;
            }
                str = place1;
                substr = place2;
                if (judge == tj_strlen(place2))
                    return place1 - stay + 1;
                else
                    judge = 0;
                continue;
            
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* stay = str;
    if (str == NULL)
        return 0;
    for (; *str != '\0'; str++)
        ;
    for (; str>=stay; str--) {
        if (*str == ch)
            return str - stay + 1;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* stay = str;
    const char* place1 = str;
    const char* place2 = substr;
    int judge = 0;
    if (str == NULL || substr == NULL)
        return 0;
    for (; *str != '\0'; str++)
        ;
    for (; str>=stay; str--) {
        if (*str == *substr) {
            place1 = str;
            for (; *str != '\0' && *substr != '\0'; str++, substr++) {
                if (*str != *substr) {
                    break;
                }
                judge++;
            }
            str = place1;
            substr = place2;
            if (judge == tj_strlen(place2))
                return place1 - stay + 1;
            else
                judge = 0;
            continue;

        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* stra = str;
    char* stay = str;
    if (str == NULL )
        return 0;
    for (; *str != '\0'; str++)
        ;
    char* strb = str-1;
    char t = 0;
    for (; stra<=strb; stra++, strb--) {
        t = *stra;
        *stra = *strb;
        *strb = t;
    }
    *str = '\0';
    return stay;
}
