/*2352467 ÐÅ08 ÕÔ°¢Ç¿*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	double num = 0;
	scanf("%lf", &num);
	int a ,b,d,e,f,g,h,i,j,k,l,m;
	double c = 1e9;
	double num1 = 0;//´´½¨ÓÃÓÚ±È½ÏÇ°ÃæÊÇ·ñÓÐÁã
	num1=num = num + 0.005;
	int count = 0;
	count=a = (int)(num / c);
	num = num - a * c;
	c /= 10;
	b = (int)(num / c);
	num = num - b * c;
	c /= 10;
	d = (int)(num / c);
	num = num - d * c;
	c /= 10;
	e= (int)(num / c);
	num = num - e* c;
	c /= 10;
	f = (int)(num / c);
	num = num - f * c;
	c /= 10;
	g = (int)(num / c);
	num = num - g * c;
	c /= 10;
	h = (int)(num / c);
	num = num - h * c;
	c /= 10;
	i = (int)(num / c);
	num = num - i * c;
	c /= 10;
	j = (int)(num / c);
	num = num - j * c;
	c /= 10;
	k = (int)(num / c);
	num = num - k * c;
	c /= 10;
	l = (int)(num / c);
	num = num - l * c;
	c /= 10;
	m = (int)(num / c);
	printf("´óÐ´½á¹ûÊÇ:\n");
	if (a != 0) {
		switch (a) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èþ");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		case 0:
			printf("Áã");
			break;
		}
		printf("Ê°");
	}
	if (b != 0) {
		switch (b) {
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èþ");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		case 0:
			printf("Áã");
			break;
		}
	}
	if (b != 0 || count != 0) {
		printf("ÒÚ");
	}

	switch (d) {
	case 1:
		printf("Ò¼Çª");
		break;
	case 2:
		printf("·¡Çª");
		break;
	case 3:
		printf("ÈþÇª");
		break;
	case 4:
		printf("ËÁÇª");
		break;
	case 5:
		printf("ÎéÇª");
		break;
	case 6:
		printf("Â½Çª");
		break;
	case 7:
		printf("ÆâÇª");
		break;
	case 8:
		printf("°ÆÇª");
		break;
	case 9:
		printf("¾ÁÇª");
		break;
	case 0:
		if ( num1>=1e8&&( e != 0 || f != 0 || g != 0))
			printf("Áã");
		break;
	}
	switch (e) {
	case 1:
		printf("Ò¼°Û");
		break;
	case 2:
		printf("·¡°Û");
		break;
	case 3:
		printf("Èþ°Û");
		break;
	case 4:
		printf("ËÁ°Û");
		break;
	case 5:
		printf("Îé°Û");
		break;
	case 6:
		printf("Â½°Û");
		break;
	case 7:
		printf("Æâ°Û");
		break;
	case 8:
		printf("°Æ°Û");
		break;
	case 9:
		printf("¾Á°Û");
		break;
	case 0:
		if (d != 0 && (f != 0 || g != 0))
			printf("Áã");
		break;
	}
    switch (f) {
	case 1:
		printf("Ò¼Ê°");
		break;
	case 2:
		printf("·¡Ê°");
		break;
	case 3:
		printf("ÈþÊ°");
		break;
	case 4:
		printf("ËÁÊ°");
		break;
	case 5:
		printf("ÎéÊ°");
		break;
	case 6:
		printf("Â½Ê°");
		break;
	case 7:
		printf("ÆâÊ°");
		break;
	case 8:
		printf("°ÆÊ°");
		break;
	case 9:
		printf("¾ÁÊ°");
		break;
	case 0:
		if (e != 0  && g != 0)
			printf("Áã");
		break;
	}
    switch (g) {
	case 1:
		printf("Ò¼");
		break;
	case 2:
		printf("·¡");
		break;
	case 3:
		printf("Èþ");
		break;
	case 4:
		printf("ËÁ");
		break;
	case 5:
		printf("Îé");
		break;
	case 6:
		printf("Â½");
		break;
	case 7:
		printf("Æâ");
		break;
	case 8:
		printf("°Æ");
		break;
	case 9:
		printf("¾Á");
		break;
	case 0:
		break;
	}
	if (d!=0||e!=0||f!=0||g!=0)
		printf("Íò");

    switch (h) {
	case 1:
		printf("Ò¼Çª");
		break;
	case 2:
		printf("·¡Çª");
		break;
	case 3:
		printf("ÈþÇª");
		break;
	case 4:
		printf("ËÁÇª");
		break;
	case 5:
		printf("ÎéÇª");
		break;
	case 6:
		printf("Â½Çª");
		break;
	case 7:
		printf("ÆâÇª");
		break;
	case 8:
		printf("°ÆÇª");
		break;
	case 9:
		printf("¾ÁÇª");
		break;
	case 0:
		if ((num1 >= 10000) && (i != 0 || j != 0 || k != 0))
			printf("Áã");
		break;
	}
	switch (i) {
	case 1:
		printf("Ò¼°Û");
		break;
	case 2:
		printf("·¡°Û");
		break;
	case 3:
		printf("Èþ°Û");
		break;
	case 4:
		printf("ËÁ°Û");
		break;
	case 5:
		printf("Îé°Û");
		break;
	case 6:
		printf("Â½°Û");
		break;
	case 7:
		printf("Æâ°Û");
		break;
	case 8:
		printf("°Æ°Û");
		break;
	case 9:
		printf("¾Á°Û");
		break;
	case 0:
		if (h != 0 && (j != 0 || k != 0))
			printf("Áã");
		break;
	}
    switch (j) {
	case 1:
		printf("Ò¼Ê°");
		break;
	case 2:
		printf("·¡Ê°");
		break;
	case 3:
		printf("ÈþÊ°");
		break;
	case 4:
		printf("ËÁÊ°");
		break;
	case 5:
		printf("ÎéÊ°");
		break;
	case 6:
		printf("Â½Ê°");
		break;
	case 7:
		printf("ÆâÊ°");
		break;
	case 8:
		printf("°ÆÊ°");
		break;
	case 9:
		printf("¾ÁÊ°");
		break;
	case 0:
		if (i != 0 && k != 0)
			printf("Áã");
		break;
	}
    switch (k) {
	case 1:
		printf("Ò¼");
		break;
	case 2:
		printf("·¡");
		break;
	case 3:
		printf("Èþ");
		break;
	case 4:
		printf("ËÁ");
		break;
	case 5:
		printf("Îé");
		break;
	case 6:
		printf("Â½");
		break;
	case 7:
		printf("Æâ");
		break;
	case 8:
		printf("°Æ");
		break;
	case 9:
		printf("¾Á");
		break;
	case 0:
		break;
	}
	if (num1 >= 1)
		printf("Ô²");
	switch (l) {
	case 1:
		printf("Ò¼½Ç");
		break;
	case 2:
		printf("·¡½Ç");
		break;
	case 3:
		printf("Èþ½Ç");
		break;
	case 4:
		printf("ËÁ½Ç");
		break;
	case 5:
		printf("Îé½Ç");
		break;
	case 6:
		printf("Â½½Ç");
		break;
	case 7:
		printf("Æâ½Ç");
		break;
	case 8:
		printf("°Æ½Ç");
		break;
	case 9:
		printf("¾Á½Ç");
		break;
	case 0:
		if (num1 >= 1 && m != 0)
			printf("Áã");
		break;
	}
    switch (m) {
	case 1:
		printf("Ò¼·Ö");
		break;
	case 2:
		printf("·¡·Ö");
		break;
	case 3:
		printf("Èþ·Ö");
		break;
	case 4:
		printf("ËÁ·Ö");
		break;
	case 5:
		printf("Îé·Ö");
		break;
	case 6:
		printf("Â½·Ö");
		break;
	case 7:
		printf("Æâ·Ö");
		break;
	case 8:
		printf("°Æ·Ö");
		break;
	case 9:
		printf("¾Á·Ö");
		break;
	case 0:
		break;
	}
	if (num1-0.005 == 0)
		printf("ÁãÔ²Õû");
	else if (m == 0 || (m == 0 && l == 0))
		printf("Õû");
	else;
	printf("\n");
    return 0;
}