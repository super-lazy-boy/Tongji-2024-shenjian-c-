/* 信08 2352467 赵阿强 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int count = 0;
    for (i = 0; str[i] != '\0'; i++) {
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
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int i = 0;
    for (i = 0; i < length2+1; i++) {
        if(i == length2)
            s1[length1 + i] = '\0';
        else
            s1[length1 + i] = s2[i];
    }
    return s1[length1+length2+1]; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int i = 0;
    int min = len < length2 ? len : length2;
    for (i = 0; i <= min; i++) {
        if (i == min)
            s1[length1 + i] = '\0';
        else
            s1[length1 + i] = s2[i];
    }
    return s1[length1 + len +1]; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    for (i = 0; i < length2+1; i++) {
        s1[i] = 0;
    }
    for (i = 0; i < length2+1; i++) {
        s1[i] = s2[i];
    }
    return s1[length2+1]; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    for (i = 0; i < len+1&&i<length2; i++) {
        s1[i] = s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cha = 0;
    int max = 0;
    int i = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    max = length1 > length2 ? length1 : length2;
    for (i = 0; i < max; i++) {
        cha = s1[i] - s2[i];
        if (cha != 0)
            break;
    }
    return cha; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cha = 0;
    int min = 0;
    int i = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    min = length1 < length2 ? length1 : length2;
    for (i = 0; i < min+1; i++) {

        if (s1[i] <= 'Z' && s1[i] >= 'A') {
            if (s2[i] <= 'Z' && s2[i] >= 'A')
                cha = s1[i] + 32 - s2[i] - 32;
            else
                cha = s1[i] + 32 - s2[i];
        }
        else {
            if (s2[i] <= 'Z' && s2[i] >= 'A')
                cha = s1[i] - s2[i] - 32;
            else
                cha = s1[i] - s2[i];
        }
        if (cha != 0)
            break;
    }
    return cha; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int min = 0;
    int i = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    min = length1 < length2 ? length1 : length2;
    int cha = 0;
    for (i = 0; i < min + 1 && i < len; i++) {
        cha = s1[i] - s2[i];
        if (cha != 0)
            break;
    }
    return cha; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int min = 0;
    int i = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    min = length1 < length2 ? length1 : length2;
    int cha = 0;
    for (i = 0; i < min + 1 && i < len; i++) {
        if (s1[i] <= 'Z' && s1[i] >= 'A') {
            if (s2[i] <= 'Z' && s2[i] >= 'A')
                cha = s1[i] + 32 - s2[i] - 32;
            else
                cha = s1[i] + 32 - s2[i];
        }
        else {
            if (s2[i] <= 'Z' && s2[i] >= 'A')
                cha = s1[i] - s2[i] - 32;
            else
                cha = s1[i] - s2[i];
        }
        if (cha != 0)
            break;
    }
    return cha; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int length = tj_strlen(str);
    for (i = 0; i < length; i++) {
        if (str[i] <= 'z' && str[i] >= 'a')
            str[i] -= 32;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int length = tj_strlen(str);
    for (i = 0; i < length; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] += 32;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int length = tj_strlen(str);
    for (i = 0; i < length; i++) {
        if (str[i] == ch)
            break;
    }
    if (i == length )
        i = -1;
    return i+1; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int j = 0;
    int length1 = tj_strlen(str);
    int length2= tj_strlen(substr);
    for (i = 0; i < length1; i++) {
        if (str[i] == substr[0]) {
            for (j = 0; j < length2; j++) {
                if (str[i + j] != substr[j])
                    break;
            }
            if (j == length2)
                break;
        }
    }
    if (i == length1)
        i = -1;
    return i+1; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int length = tj_strlen(str);
    for (i = length-1; i >=0; i--) {
        if (str[i] == ch)
            break;
    }
    return i + 1; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int j = 0;
    int length1 = tj_strlen(str);
    int length2 = tj_strlen(substr);
    for (i = length1-1; i >=0; i--) {
        if (str[i] == substr[0]) {
            for (j = 0; j < length2; j++) {
                if (str[i + j] != substr[j])
                    break;
            }
            if (j == length2)
                break;
        }
    }
    return i + 1; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i = 0;
    int length = tj_strlen(str);
    int  t = 0;
    int mid = (tj_strlen(str) + 1) / 2;
    for (i = 0; i <mid; i++) {
        t = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = t;
    }
    return 0; //return值可根据需要修改
}
