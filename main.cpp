#include "CText.h"
#include "tchar_utils.h"
#include <vector>
#include <algorithm>
class Numeral
{
public:
    int value;
    // Cases падеж, числительное
    std::vector < std::pair<CText, CText> > Cases;
    // содержится лм слово в формах этого числительного
    bool contains(CText str)
    {
        for (auto f : Cases)
        {
            if (f.second == str)
            {
                return true;
            }
        }
        return false;
    }
    // получить слово по падежу
    CText getWordByCase(CText CaseName)
    {
        for (auto f : Cases)
        {
            CText frm = f.first;
            if (frm.length() == 3 && CaseName.length()==2)
            {
                frm.cutLeft(1);
            }
            if (frm.length() == 2 && CaseName.length() == 3)
            {
                CaseName.cutLeft(1);
            }
            if (frm == CaseName)
            {
                return f.second;
            }
                       
        }

        if (CaseName[0] == _T('ч'))
        {
            CaseName[0] = _T('м');
        }else
        {
            return _T("");
        }

        for (auto f : Cases)
        {
            CText frm = f.first;
            if (frm.length() == 3 && CaseName.length() == 2)
            {
                frm.cutLeft(1);
            }
            if (frm.length() == 2 && CaseName.length() == 3)
            {
                CaseName.cutLeft(1);
            }
            if (frm == CaseName)
            {
                return f.second;
            }

        }

        return _T("");
    }
    // получить список возможных падежей заданного слова
    std::vector <CText> getCaseByWord(CText word)
    {
        std::vector <CText> result;
        for (auto f : Cases)
        {
            if (f.second == word)
            {
                result.push_back(f.first);
            }
        }
        return result;
    }
};

class Numerals
{
private:
    Numeral num_1, num_2, num_3,
     num_4, num_5, num_6, num_7,
     num_8, num_9, num_10,num_11,
     num_12,num_13,num_14,num_15,
     num_16,num_17,num_18,num_19,
     num_20,num_30,num_40,num_50,
     num_60,num_70,num_80,num_90,
     num_100,num_200,num_300,num_400,
     num_500,num_600,num_700,num_800,
     num_900;

    std::vector<Numeral> numerals;
public:
    
// ПАДЕЖ        ВОПРОС                  ПРЕДЛОГИ 
// Именительный (есть)кто? что?         -
// Родительный  (нет)кого? чего?        с, у, от, до, из, без, для, вокруг, около, возле, кроме
// Дательный    (дать)кому? чему?       к, по, благодаря, вопреки, согласно
// Винительный  (вижу)кого? что?        под, за, про, через, в, на, во
// Творительный (доволен)кем? чем?      с, со, за, над, под, между, перед
// Предложный   (думать)о ком? о чем?   в, о, об, на, при, по
    Numerals()
    {
        num_1.value = 1;
        num_1.Cases.push_back(std::make_pair(_T("мип"), _T("один")));
        num_1.Cases.push_back(std::make_pair(_T("жип"), _T("одна")));
        num_1.Cases.push_back(std::make_pair(_T("мвп"), _T("один")));
        num_1.Cases.push_back(std::make_pair(_T("жвп"), _T("одну")));
        num_1.Cases.push_back(std::make_pair(_T("мрп"), _T("одном")));
        num_1.Cases.push_back(std::make_pair(_T("жрп"), _T("одной")));
        num_1.Cases.push_back(std::make_pair(_T("мтп"), _T("одним")));
        num_1.Cases.push_back(std::make_pair(_T("жтп"), _T("одной")));
        num_1.Cases.push_back(std::make_pair(_T("мдп"), _T("одному")));
        num_1.Cases.push_back(std::make_pair(_T("ждп"), _T("одной")));
        num_1.Cases.push_back(std::make_pair(_T("мпп"), _T("одном")));
        num_1.Cases.push_back(std::make_pair(_T("жпп"), _T("одной")));

        num_2.value = 2;
        num_2.Cases.push_back(std::make_pair(_T("мип"), _T("два")));
        num_2.Cases.push_back(std::make_pair(_T("жип"), _T("две")));
        num_2.Cases.push_back(std::make_pair(_T("мвп"), _T("два")));
        num_2.Cases.push_back(std::make_pair(_T("жвп"), _T("две")));
        num_2.Cases.push_back(std::make_pair(_T("рп"), _T("двух")));
        num_2.Cases.push_back(std::make_pair(_T("тп"), _T("двумя")));
        num_2.Cases.push_back(std::make_pair(_T("дп"), _T("двум")));
        num_2.Cases.push_back(std::make_pair(_T("пп"), _T("двух")));

        num_3.value = 3;
        num_3.Cases.push_back(std::make_pair(_T("ип"), _T("три")));
        num_3.Cases.push_back(std::make_pair(_T("вп"), _T("три")));
        num_3.Cases.push_back(std::make_pair(_T("рп"), _T("трех")));
        num_3.Cases.push_back(std::make_pair(_T("тп"), _T("тремя")));
        num_3.Cases.push_back(std::make_pair(_T("дп"), _T("трем")));
        num_3.Cases.push_back(std::make_pair(_T("пп"), _T("трех")));

        num_4.value = 4;
        num_4.Cases.push_back(std::make_pair(_T("ип"), _T("четыре")));
        num_4.Cases.push_back(std::make_pair(_T("вп"), _T("четыре")));
        num_4.Cases.push_back(std::make_pair(_T("рп"), _T("четырех")));
        num_4.Cases.push_back(std::make_pair(_T("тп"), _T("четырьмя")));
        num_4.Cases.push_back(std::make_pair(_T("дп"), _T("четырем")));
        num_4.Cases.push_back(std::make_pair(_T("пп"), _T("четырех")));

        num_5.value = 5;
        num_5.Cases.push_back(std::make_pair(_T("ип"), _T("пять")));
        num_5.Cases.push_back(std::make_pair(_T("вп"), _T("пять")));
        num_5.Cases.push_back(std::make_pair(_T("рп"), _T("пяти")));
        num_5.Cases.push_back(std::make_pair(_T("тп"), _T("пятью")));
        num_5.Cases.push_back(std::make_pair(_T("дп"), _T("пяти")));
        num_5.Cases.push_back(std::make_pair(_T("пп"), _T("пяти")));

        num_6.value = 6;
        num_6.Cases.push_back(std::make_pair(_T("ип"), _T("шесть")));
        num_6.Cases.push_back(std::make_pair(_T("вп"), _T("шесть")));
        num_6.Cases.push_back(std::make_pair(_T("рп"), _T("шести")));
        num_6.Cases.push_back(std::make_pair(_T("тп"), _T("шестью")));
        num_6.Cases.push_back(std::make_pair(_T("дп"), _T("шести")));
        num_6.Cases.push_back(std::make_pair(_T("пп"), _T("шести")));

        num_7.value = 7;
        num_7.Cases.push_back(std::make_pair(_T("ип"), _T("семь")));
        num_7.Cases.push_back(std::make_pair(_T("вп"), _T("семь")));
        num_7.Cases.push_back(std::make_pair(_T("рп"), _T("семи")));
        num_7.Cases.push_back(std::make_pair(_T("тп"), _T("семью")));
        num_7.Cases.push_back(std::make_pair(_T("дп"), _T("семи")));
        num_7.Cases.push_back(std::make_pair(_T("пп"), _T("семи")));

        num_8.value = 8;
        num_8.Cases.push_back(std::make_pair(_T("ип"), _T("восемь")));
        num_8.Cases.push_back(std::make_pair(_T("вп"), _T("восемь")));
        num_8.Cases.push_back(std::make_pair(_T("рп"), _T("восьми")));
        num_8.Cases.push_back(std::make_pair(_T("тп"), _T("восемью")));
        num_8.Cases.push_back(std::make_pair(_T("тп"), _T("восьмью")));
        num_8.Cases.push_back(std::make_pair(_T("дп"), _T("восьми")));
        num_8.Cases.push_back(std::make_pair(_T("пп"), _T("восьми")));

        num_9.value = 9;
        num_9.Cases.push_back(std::make_pair(_T("ип"), _T("девять")));
        num_9.Cases.push_back(std::make_pair(_T("вп"), _T("девять")));
        num_9.Cases.push_back(std::make_pair(_T("рп"), _T("девяти")));
        num_9.Cases.push_back(std::make_pair(_T("тп"), _T("девятью")));
        num_9.Cases.push_back(std::make_pair(_T("дп"), _T("девяти")));
        num_9.Cases.push_back(std::make_pair(_T("пп"), _T("девяти")));

        num_10.value = 10;
        num_10.Cases.push_back(std::make_pair(_T("ип"), _T("десять")));
        num_10.Cases.push_back(std::make_pair(_T("вп"), _T("десять")));
        num_10.Cases.push_back(std::make_pair(_T("рп"), _T("десяти")));
        num_10.Cases.push_back(std::make_pair(_T("тп"), _T("десятью")));
        num_10.Cases.push_back(std::make_pair(_T("дп"), _T("десяти")));
        num_10.Cases.push_back(std::make_pair(_T("пп"), _T("десяти")));

        num_11.value = 11;
        num_11.Cases.push_back(std::make_pair(_T("ип"), _T("одинадцать")));
        num_11.Cases.push_back(std::make_pair(_T("вп"), _T("одинадцать")));
        num_11.Cases.push_back(std::make_pair(_T("рп"), _T("одинадцати")));
        num_11.Cases.push_back(std::make_pair(_T("тп"), _T("одинадцатью")));
        num_11.Cases.push_back(std::make_pair(_T("дп"), _T("одинадцати")));
        num_11.Cases.push_back(std::make_pair(_T("пп"), _T("одинадцати")));

        num_12.value = 12;
        num_12.Cases.push_back(std::make_pair(_T("ип"), _T("двенадцать")));
        num_12.Cases.push_back(std::make_pair(_T("вп"), _T("двенадцать")));
        num_12.Cases.push_back(std::make_pair(_T("рп"), _T("двенадцати")));
        num_12.Cases.push_back(std::make_pair(_T("тп"), _T("двенадцатью")));
        num_12.Cases.push_back(std::make_pair(_T("дп"), _T("двенадцати")));
        num_12.Cases.push_back(std::make_pair(_T("пп"), _T("двенадцати")));

        num_13.value = 13;
        num_13.Cases.push_back(std::make_pair(_T("ип"), _T("тринадцать")));
        num_13.Cases.push_back(std::make_pair(_T("вп"), _T("тринадцать")));
        num_13.Cases.push_back(std::make_pair(_T("рп"), _T("тринадцати")));
        num_13.Cases.push_back(std::make_pair(_T("тп"), _T("тринадцатью")));
        num_13.Cases.push_back(std::make_pair(_T("дп"), _T("тринадцати")));
        num_13.Cases.push_back(std::make_pair(_T("пп"), _T("тринадцати")));

        num_14.value = 14;
        num_14.Cases.push_back(std::make_pair(_T("ип"), _T("четырнадцать")));
        num_14.Cases.push_back(std::make_pair(_T("вп"), _T("четырнадцать")));
        num_14.Cases.push_back(std::make_pair(_T("рп"), _T("четырнадцати")));
        num_14.Cases.push_back(std::make_pair(_T("тп"), _T("четырнадцатью")));
        num_14.Cases.push_back(std::make_pair(_T("дп"), _T("четырнадцати")));
        num_14.Cases.push_back(std::make_pair(_T("пп"), _T("четырнадцати")));

        num_15.value = 15;
        num_15.Cases.push_back(std::make_pair(_T("ип"), _T("пятнадцать")));
        num_15.Cases.push_back(std::make_pair(_T("вп"), _T("пятнадцать")));
        num_15.Cases.push_back(std::make_pair(_T("рп"), _T("пятнадцати")));
        num_15.Cases.push_back(std::make_pair(_T("тп"), _T("пятнадцатью")));
        num_15.Cases.push_back(std::make_pair(_T("дп"), _T("пятнадцати")));
        num_15.Cases.push_back(std::make_pair(_T("пп"), _T("пятнадцати")));

        num_16.value = 16;
        num_16.Cases.push_back(std::make_pair(_T("ип"), _T("шестнадцать")));
        num_16.Cases.push_back(std::make_pair(_T("вп"), _T("шестнадцать")));
        num_16.Cases.push_back(std::make_pair(_T("рп"), _T("шестнадцати")));
        num_16.Cases.push_back(std::make_pair(_T("тп"), _T("шестнадцатью")));
        num_16.Cases.push_back(std::make_pair(_T("дп"), _T("шестнадцати")));
        num_16.Cases.push_back(std::make_pair(_T("пп"), _T("шестнадцати")));

        num_17.value = 17;
        num_17.Cases.push_back(std::make_pair(_T("ип"), _T("семнадцать")));
        num_17.Cases.push_back(std::make_pair(_T("вп"), _T("семнадцать")));
        num_17.Cases.push_back(std::make_pair(_T("рп"), _T("семнадцати")));
        num_17.Cases.push_back(std::make_pair(_T("тп"), _T("семнадцатью")));
        num_17.Cases.push_back(std::make_pair(_T("дп"), _T("семнадцати")));
        num_17.Cases.push_back(std::make_pair(_T("пп"), _T("семнадцати")));

        num_18.value = 18;
        num_18.Cases.push_back(std::make_pair(_T("ип"), _T("восемнадцать")));
        num_18.Cases.push_back(std::make_pair(_T("вп"), _T("восемнадцать")));
        num_18.Cases.push_back(std::make_pair(_T("рп"), _T("восемнадцати")));
        num_18.Cases.push_back(std::make_pair(_T("тп"), _T("восемнадцатью")));
        num_18.Cases.push_back(std::make_pair(_T("дп"), _T("восемнадцати")));
        num_18.Cases.push_back(std::make_pair(_T("пп"), _T("восемнадцати")));

        num_19.value = 19;
        num_19.Cases.push_back(std::make_pair(_T("ип"), _T("девятнадцать")));
        num_19.Cases.push_back(std::make_pair(_T("вп"), _T("девятнадцать")));
        num_19.Cases.push_back(std::make_pair(_T("рп"), _T("девятнадцати")));
        num_19.Cases.push_back(std::make_pair(_T("тп"), _T("девятнадцатью")));
        num_19.Cases.push_back(std::make_pair(_T("дп"), _T("девятнадцати")));
        num_19.Cases.push_back(std::make_pair(_T("пп"), _T("девятнадцати")));

        num_20.value = 20;
        num_20.Cases.push_back(std::make_pair(_T("ип"), _T("двадцать")));
        num_20.Cases.push_back(std::make_pair(_T("вп"), _T("двадцать")));
        num_20.Cases.push_back(std::make_pair(_T("рп"), _T("двадцати")));
        num_20.Cases.push_back(std::make_pair(_T("тп"), _T("двадцатью")));
        num_20.Cases.push_back(std::make_pair(_T("дп"), _T("двадцати")));
        num_20.Cases.push_back(std::make_pair(_T("пп"), _T("двадцати")));
        
        num_30.value = 30;
        num_30.Cases.push_back(std::make_pair(_T("ип"), _T("тридцать")));
        num_30.Cases.push_back(std::make_pair(_T("вп"), _T("тридцать")));
        num_30.Cases.push_back(std::make_pair(_T("рп"), _T("тридцати")));
        num_30.Cases.push_back(std::make_pair(_T("тп"), _T("тридцатью")));
        num_30.Cases.push_back(std::make_pair(_T("дп"), _T("тридцати")));
        num_30.Cases.push_back(std::make_pair(_T("пп"), _T("тридцати")));

        num_40.value = 40;
        num_40.Cases.push_back(std::make_pair(_T("ип"), _T("сорок")));
        num_40.Cases.push_back(std::make_pair(_T("вп"), _T("сорок")));
        num_40.Cases.push_back(std::make_pair(_T("рп"), _T("сорока")));
        num_40.Cases.push_back(std::make_pair(_T("тп"), _T("сорока")));
        num_40.Cases.push_back(std::make_pair(_T("дп"), _T("сорока")));
        num_40.Cases.push_back(std::make_pair(_T("пп"), _T("сорока")));

        num_50.value = 50;
        num_50.Cases.push_back(std::make_pair(_T("ип"), _T("пятьдесят")));
        num_50.Cases.push_back(std::make_pair(_T("вп"), _T("пятьдесят")));
        num_50.Cases.push_back(std::make_pair(_T("рп"), _T("пятидесяти")));
        num_50.Cases.push_back(std::make_pair(_T("тп"), _T("пятьюдесятью")));
        num_50.Cases.push_back(std::make_pair(_T("дп"), _T("пятидесяти")));
        num_50.Cases.push_back(std::make_pair(_T("пп"), _T("пятидесяти")));
        
        num_60.value = 60;
        num_60.Cases.push_back(std::make_pair(_T("ип"), _T("шестьдесят")));
        num_60.Cases.push_back(std::make_pair(_T("вп"), _T("шестьдесят")));
        num_60.Cases.push_back(std::make_pair(_T("рп"), _T("шестидесяти")));
        num_60.Cases.push_back(std::make_pair(_T("тп"), _T("шестидесятью")));
        num_60.Cases.push_back(std::make_pair(_T("дп"), _T("шестидесяти")));
        num_60.Cases.push_back(std::make_pair(_T("пп"), _T("шестидесяти")));

        num_70.value = 70;
        num_70.Cases.push_back(std::make_pair(_T("ип"), _T("семьдесят")));
        num_70.Cases.push_back(std::make_pair(_T("вп"), _T("семьдесят")));
        num_70.Cases.push_back(std::make_pair(_T("рп"), _T("семидесяти")));
        num_70.Cases.push_back(std::make_pair(_T("тп"), _T("семидесятью")));
        num_70.Cases.push_back(std::make_pair(_T("дп"), _T("семидесяти")));
        num_70.Cases.push_back(std::make_pair(_T("пп"), _T("семидесяти")));

        num_80.value = 80;
        num_80.Cases.push_back(std::make_pair(_T("ип"), _T("восемьдесят")));
        num_80.Cases.push_back(std::make_pair(_T("вп"), _T("восемьдесят")));
        num_80.Cases.push_back(std::make_pair(_T("рп"), _T("восьмидесяти")));
        num_80.Cases.push_back(std::make_pair(_T("тп"), _T("восьмьюдесятью")));
        num_80.Cases.push_back(std::make_pair(_T("тп"), _T("восемьюдесятью")));
        num_80.Cases.push_back(std::make_pair(_T("дп"), _T("восьмидесяти")));
        num_80.Cases.push_back(std::make_pair(_T("пп"), _T("шестидесяти")));

        num_90.value = 90;
        num_90.Cases.push_back(std::make_pair(_T("ип"), _T("девяносто")));
        num_90.Cases.push_back(std::make_pair(_T("вп"), _T("девяносто")));
        num_90.Cases.push_back(std::make_pair(_T("рп"), _T("девяноста")));
        num_90.Cases.push_back(std::make_pair(_T("тп"), _T("девяноста")));
        num_90.Cases.push_back(std::make_pair(_T("дп"), _T("девяноста")));
        num_90.Cases.push_back(std::make_pair(_T("пп"), _T("девяноста")));

        num_100.value = 100;
        num_100.Cases.push_back(std::make_pair(_T("ип"), _T("сто")));
        num_100.Cases.push_back(std::make_pair(_T("вп"), _T("сто")));
        num_100.Cases.push_back(std::make_pair(_T("рп"), _T("ста")));
        num_100.Cases.push_back(std::make_pair(_T("тп"), _T("ста")));
        num_100.Cases.push_back(std::make_pair(_T("дп"), _T("ста")));
        num_100.Cases.push_back(std::make_pair(_T("пп"), _T("ста")));

        num_200.value = 200;
        num_200.Cases.push_back(std::make_pair(_T("ип"), _T("двести")));
        num_200.Cases.push_back(std::make_pair(_T("вп"), _T("двести")));
        num_200.Cases.push_back(std::make_pair(_T("рп"), _T("двухсот")));
        num_200.Cases.push_back(std::make_pair(_T("тп"), _T("двумястами")));
        num_200.Cases.push_back(std::make_pair(_T("дп"), _T("двумстам")));
        num_200.Cases.push_back(std::make_pair(_T("пп"), _T("двухстах")));

        num_300.value = 300;
        num_300.Cases.push_back(std::make_pair(_T("ип"), _T("триста")));
        num_300.Cases.push_back(std::make_pair(_T("вп"), _T("триста")));
        num_300.Cases.push_back(std::make_pair(_T("рп"), _T("трехсот")));
        num_300.Cases.push_back(std::make_pair(_T("тп"), _T("тремястами")));
        num_300.Cases.push_back(std::make_pair(_T("дп"), _T("тремстам")));
        num_300.Cases.push_back(std::make_pair(_T("пп"), _T("трехстах")));

        num_400.value = 400;
        num_400.Cases.push_back(std::make_pair(_T("ип"), _T("четыреста")));
        num_400.Cases.push_back(std::make_pair(_T("вп"), _T("четыреста")));
        num_400.Cases.push_back(std::make_pair(_T("рп"), _T("четырехсот")));
        num_400.Cases.push_back(std::make_pair(_T("тп"), _T("четырьмястами")));
        num_400.Cases.push_back(std::make_pair(_T("дп"), _T("четыремстам")));
        num_400.Cases.push_back(std::make_pair(_T("пп"), _T("четырехстах")));

        num_500.value = 500;
        num_500.Cases.push_back(std::make_pair(_T("ип"), _T("пятьсот")));
        num_500.Cases.push_back(std::make_pair(_T("вп"), _T("пятьсот")));
        num_500.Cases.push_back(std::make_pair(_T("рп"), _T("пятисот")));
        num_500.Cases.push_back(std::make_pair(_T("тп"), _T("пятистами")));
        num_500.Cases.push_back(std::make_pair(_T("дп"), _T("пятистам")));
        num_500.Cases.push_back(std::make_pair(_T("пп"), _T("пятистах")));

        num_600.value = 600;
        num_600.Cases.push_back(std::make_pair(_T("ип"), _T("шестьсот")));
        num_600.Cases.push_back(std::make_pair(_T("вп"), _T("шестьсот")));
        num_600.Cases.push_back(std::make_pair(_T("рп"), _T("шестисот")));
        num_600.Cases.push_back(std::make_pair(_T("тп"), _T("шестьюстами")));
        num_600.Cases.push_back(std::make_pair(_T("дп"), _T("шестистам")));
        num_600.Cases.push_back(std::make_pair(_T("пп"), _T("трехстах")));

        num_700.value = 700;
        num_700.Cases.push_back(std::make_pair(_T("ип"), _T("семьсот")));
        num_700.Cases.push_back(std::make_pair(_T("вп"), _T("семьсот")));
        num_700.Cases.push_back(std::make_pair(_T("рп"), _T("семисот")));
        num_700.Cases.push_back(std::make_pair(_T("тп"), _T("семьюстами")));
        num_700.Cases.push_back(std::make_pair(_T("дп"), _T("семистам")));
        num_700.Cases.push_back(std::make_pair(_T("пп"), _T("семистах")));

        num_800.value = 800;
        num_800.Cases.push_back(std::make_pair(_T("ип"), _T("восемьсот")));
        num_800.Cases.push_back(std::make_pair(_T("вп"), _T("восемьсот")));
        num_800.Cases.push_back(std::make_pair(_T("рп"), _T("восьмисот")));
        num_800.Cases.push_back(std::make_pair(_T("тп"), _T("восемьюстами")));
        num_800.Cases.push_back(std::make_pair(_T("тп"), _T("восьмьюстами")));
        num_800.Cases.push_back(std::make_pair(_T("дп"), _T("восьмистам")));
        num_800.Cases.push_back(std::make_pair(_T("пп"), _T("восьмистах")));

        num_900.value = 900;
        num_900.Cases.push_back(std::make_pair(_T("ип"), _T("девятьсот")));
        num_900.Cases.push_back(std::make_pair(_T("вп"), _T("девятьсот")));
        num_900.Cases.push_back(std::make_pair(_T("рп"), _T("девятисот")));
        num_900.Cases.push_back(std::make_pair(_T("тп"), _T("девятистами")));
        num_900.Cases.push_back(std::make_pair(_T("дп"), _T("девятистам")));
        num_900.Cases.push_back(std::make_pair(_T("пп"), _T("девятистах")));
        
        numerals =
        { num_1,num_2,num_3,num_4,num_5,
        num_6,num_7,num_8,num_9,num_10,
        num_11,num_12,num_13,num_14,num_15,
        num_16,num_17,num_18,num_19,num_20,
        num_30,num_40,num_50,num_60,num_70,
        num_80,num_90,num_100,num_200,num_300,
        num_400,num_500,num_600,num_700,num_800,
        num_900 };
    }

    // мы обрабатываем знак отдельно, поэтому здесь
    // -1 означает ошибку.
    int getValue(CText str)
    {
        for (auto N : numerals)
        {
            if (N.contains(str))
            {
                return N.value;
            }
        }
        return -1;
    }

    //CText getWordByCase(CText CaseName)
    
    CText getWordInCase(CText src, CText Case)
    {        
        for (auto N : numerals)
        {
            if (N.contains(src))
            {
                return N.getWordByCase(Case);
            }
        }
        return _T("");
    }
};
class Multipliers
{
private:
    Numeral num_1e3, num_1e6, num_1e9, num_1e12;
    std::vector<Numeral> multipliers;
public:

    // ПАДЕЖ        ВОПРОС                  ПРЕДЛОГИ 
    // Именительный (есть)кто? что?         -
    // Родительный  (нет)кого? чего?        с, у, от, до, из, без, для, вокруг, около, возле, кроме
    // Дательный    (дать)кому? чему?       к, по, благодаря, вопреки, согласно
    // Винительный  (вижу)кого? что?        под, за, про, через, в, на, во
    // Творительный (доволен)кем? чем?      с, со, за, над, под, между, перед
    // Предложный   (думать)о ком? о чем?   в, о, об, на, при, по
    Multipliers()
    {
        num_1e3.value = 3;
        num_1e3.Cases.push_back(std::make_pair(_T("еип"), _T("тысяча")));
        num_1e3.Cases.push_back(std::make_pair(_T("евп"), _T("тысячу")));
        num_1e3.Cases.push_back(std::make_pair(_T("ерп"), _T("тысячи")));
        num_1e3.Cases.push_back(std::make_pair(_T("етп"), _T("тысячей")));
        num_1e3.Cases.push_back(std::make_pair(_T("едп"), _T("тысячe")));
        num_1e3.Cases.push_back(std::make_pair(_T("епп"), _T("тысяче")));

        num_1e3.Cases.push_back(std::make_pair(_T("мип"), _T("тысяч")));
        num_1e3.Cases.push_back(std::make_pair(_T("чип"), _T("тысячи")));
        num_1e3.Cases.push_back(std::make_pair(_T("мвп"), _T("тысячи")));
        num_1e3.Cases.push_back(std::make_pair(_T("мрп"), _T("тысяч")));
        num_1e3.Cases.push_back(std::make_pair(_T("мтп"), _T("тысячами")));
        num_1e3.Cases.push_back(std::make_pair(_T("мдп"), _T("тысячам")));
        num_1e3.Cases.push_back(std::make_pair(_T("мпп"), _T("тысячах")));


        num_1e6.value = 6;
        num_1e6.Cases.push_back(std::make_pair(_T("еип"), _T("миллион")));
        num_1e6.Cases.push_back(std::make_pair(_T("евп"), _T("миллиону")));              
        num_1e6.Cases.push_back(std::make_pair(_T("ерп"), _T("миллиона")));
        num_1e6.Cases.push_back(std::make_pair(_T("етп"), _T("миллионом")));
        num_1e6.Cases.push_back(std::make_pair(_T("едп"), _T("миллиону")));
        num_1e6.Cases.push_back(std::make_pair(_T("епп"), _T("миллионе")));

        num_1e6.Cases.push_back(std::make_pair(_T("мип"), _T("миллионов")));
        num_1e6.Cases.push_back(std::make_pair(_T("чип"), _T("миллиона"))); // 234
        num_1e6.Cases.push_back(std::make_pair(_T("мвп"), _T("миллионов")));
        num_1e6.Cases.push_back(std::make_pair(_T("чвп"), _T("миллиона"))); // 234
        num_1e6.Cases.push_back(std::make_pair(_T("мрп"), _T("миллионов")));         
        num_1e6.Cases.push_back(std::make_pair(_T("мтп"), _T("миллионами")));
        num_1e6.Cases.push_back(std::make_pair(_T("мдп"), _T("миллионам")));
        num_1e6.Cases.push_back(std::make_pair(_T("мпп"), _T("миллионах")));

        num_1e9.value = 9;
        num_1e9.Cases.push_back(std::make_pair(_T("еип"), _T("миллиард")));
        num_1e9.Cases.push_back(std::make_pair(_T("евп"), _T("миллиард")));             
        num_1e9.Cases.push_back(std::make_pair(_T("ерп"), _T("миллиарда")));
        num_1e9.Cases.push_back(std::make_pair(_T("етп"), _T("миллиардом")));
        num_1e9.Cases.push_back(std::make_pair(_T("едп"), _T("миллиарду")));
        num_1e9.Cases.push_back(std::make_pair(_T("епп"), _T("миллиарде")));

        num_1e9.Cases.push_back(std::make_pair(_T("мип"), _T("миллиардов")));
        num_1e9.Cases.push_back(std::make_pair(_T("чип"), _T("миллиарда")));
        num_1e9.Cases.push_back(std::make_pair(_T("мвп"), _T("миллиардов")));
        num_1e9.Cases.push_back(std::make_pair(_T("чвп"), _T("миллиарда")));
        num_1e9.Cases.push_back(std::make_pair(_T("мрп"), _T("миллиардов")));
        num_1e9.Cases.push_back(std::make_pair(_T("мтп"), _T("миллиардами")));
        num_1e9.Cases.push_back(std::make_pair(_T("мдп"), _T("миллиардам")));
        num_1e9.Cases.push_back(std::make_pair(_T("мпп"), _T("миллиардах")));


        num_1e12.value = 12;
        num_1e12.Cases.push_back(std::make_pair(_T("еип"), _T("триллион")));
        num_1e12.Cases.push_back(std::make_pair(_T("евп"), _T("триллион")));               
        num_1e12.Cases.push_back(std::make_pair(_T("ерп"), _T("триллиона")));
        num_1e12.Cases.push_back(std::make_pair(_T("етп"), _T("триллионом")));
        num_1e12.Cases.push_back(std::make_pair(_T("едп"), _T("триллиону")));
        num_1e12.Cases.push_back(std::make_pair(_T("епп"), _T("триллионе")));

        num_1e12.Cases.push_back(std::make_pair(_T("мип"), _T("триллионов")));
        num_1e12.Cases.push_back(std::make_pair(_T("чип"), _T("триллиона")));
        num_1e12.Cases.push_back(std::make_pair(_T("мвп"), _T("триллионов")));
        num_1e12.Cases.push_back(std::make_pair(_T("чвп"), _T("триллиона")));

        num_1e12.Cases.push_back(std::make_pair(_T("мрп"), _T("триллионов")));
        //num_1e12.Cases.push_back(std::make_pair(_T("чрп"), _T("триллионов")));
        num_1e12.Cases.push_back(std::make_pair(_T("мтп"), _T("триллионами")));
        num_1e12.Cases.push_back(std::make_pair(_T("мдп"), _T("триллионам")));
        num_1e12.Cases.push_back(std::make_pair(_T("мпп"), _T("триллионах")));

        multipliers = { num_1e3,num_1e6,num_1e9,num_1e12 };
    }

    

    // мы обрабатываем знак отдельно, поэтому здесь
    // -1 означает ошибку.
    int getValue(CText str)
    {
        for (auto M : multipliers)
        {
            if (M.contains(str))
            {
                return M.value;
            }
        }
        return -1;
    }

    CText getWordInCase(CText src, CText Case)
    {
        for (auto N : multipliers)
        {
            if (N.contains(src))
            {
                return N.getWordByCase(Case);
            }
        }
        return _T("");
    }

};


long long int str2num(CText& str)
{
    Numerals numbers;
    Multipliers multipliers;

    std::map<int, CText> total = {
       {12 , CText(_T("000"))},
       {9  , CText(_T("000"))},
       {6  , CText(_T("000"))},
       {3  , CText(_T("000"))},
       {0  , CText(_T("000"))} };

    std::vector<CText> words;
    str.collectWords(words, _T(" "));

    int group = 0;

    for (auto word : words)
    {
        int val = numbers.getValue(word);
        int mul = multipliers.getValue(word);
        if (val!=-1)
            group += val;
        else if (mul!=-1)
        {
            wchar_t buf[256];
            swprintf(buf, L"%03d", group);
            total[mul] = buf;
            group = 0;
        }
        else
        {
            std::wcout << L"Неизвестное слово :" << word << std::endl;
        }
        // debug
        //std::wcout << L"Degug: " << word << L" : " << group << std::endl;
    }

    if (group)
    {
        wchar_t buf[256];
        swprintf(buf, L"%03d", group);
        total[0] = buf;
    }
    CText result_str;
    std::map<int, CText>::reverse_iterator it=total.rbegin();
    for (;it!=total.rend();++it)
    {
        result_str = result_str+(it->second);
    }
    result_str.trimLeft(_T("0"));
    bool ok;
    long long int res = result_str.toInteger(ok);
    if (!ok)
    {
        std::wcout << L"Ошибка преобразования. Строка : " << result_str << std::endl;
        return -1;
    }
    return res;
}


CText towords(long long int numb)
{
    int N = 16;
    //массив, для определения разряда, в котором находимся(сотни,десятки,еденицы...)
    std::vector <long long int> osn(N);
    osn[0] = 0;
    osn[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        osn[i] = osn[i - 1] * 10;
    }
    //массив оснований
    CText basis[10][10] = {
        {_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),_T(""),_T("")},
        {_T(""),_T("один"),_T("два"),_T("три"),_T("четыре"),_T("пять"),_T("шесть"),_T("семь"),_T("восемь"),_T("девять")},
        {_T(""),_T("десять"),_T("двадцать"),_T("тридцать"),_T("сорок"),_T("пятьдесят"),_T("шестьдесят"),_T("семьдесят"),_T("восемьдесят"),_T("девяносто")},
        {_T(""),_T("сто"),_T("двести"),_T("триста"),_T("четыреста"),_T("пятьсот"),_T("шестьсот"),_T("семьсот"),_T("восемьсот"),_T("девятьсот")},
 
        {_T(""),_T("одна"),_T("две"),_T("три"),_T("четыре"),_T("пять"),_T("шесть"),_T("семь"),_T("восемь"),_T("девять")},
        {_T(""),_T("десять"),_T("двадцать"),_T("тридцать"),_T("сорок"),_T("пятьдесят"),_T("шестьдесят"),_T("семьдесят"),_T("восемьдесят"),_T("девяносто")},
        {_T(""),_T("сто"),_T("двести"),_T("триста"),_T("четыреста"),_T("пятьсот"),_T("шестьсот"),_T("семьсот"),_T("восемьсот"),_T("девятьсот")},

        {_T(""),_T("один"),_T("два"),_T("три"),_T("четыре"),_T("пять"),_T("шесть"),_T("семь"),_T("восемь"),_T("девять")},
        {_T(""),_T("десять"),_T("двадцать"),_T("тридцать"),_T("сорок"),_T("пятьдесят"),_T("шестьдесят"),_T("семьдесят"),_T("восемьдесят"),_T("девяносто")},
        {_T(""),_T("сто"),_T("двести"),_T("триста"),_T("четыреста"),_T("пятьсот"),_T("шестьсот"),_T("семьсот"),_T("восемьсот"),_T("девятьсот")}
    };

//   CText pwrs[] = { _T("тысяч"),_T("миллион"),_T("миллиард"),_T("триллион") };
//   CText endings[] = { _T(""),_T("а"),_T("а"),_T("триллион") };
    //массив окончаний
    CText termination[10][13] = {
        {_T(""),_T(""),_T(""),_T("тысяч"), _T(""),_T(""),_T("миллионов"),_T(""),_T(""),_T("миллиардов"),_T(""),_T(""),_T("триллионов")},
        {_T(""),_T(""),_T(""),_T("тысяча"),_T(""),_T(""),_T("миллион"),  _T(""),_T(""),_T("миллиард")  ,_T(""),_T(""),_T("триллион")},
        {_T(""),_T(""),_T(""),_T("тысячи"),_T(""),_T(""),_T("миллиона"), _T(""),_T(""),_T("миллиарда") ,_T(""),_T(""),_T("триллиона")} ,
        {_T(""),_T(""),_T(""),_T("тысячи"),_T(""),_T(""),_T("миллиона"), _T(""),_T(""),_T("миллиарда") ,_T(""),_T(""),_T("триллиона")} ,
        {_T(""),_T(""),_T(""),_T("тысячи"),_T(""),_T(""),_T("миллиона"), _T(""),_T(""),_T("миллиарда") ,_T(""),_T(""),_T("триллиона")} ,
        {_T(""),_T(""),_T(""),_T("тысяч"), _T(""),_T(""),_T("миллионов"),_T(""),_T(""),_T("миллиардов"),_T(""),_T(""),_T("триллионов")},
        {_T(""),_T(""),_T(""),_T("тысяч"), _T(""),_T(""),_T("миллионов"),_T(""),_T(""),_T("миллиардов"),_T(""),_T(""),_T("триллионов")},
        {_T(""),_T(""),_T(""),_T("тысяч"), _T(""),_T(""),_T("миллионов"),_T(""),_T(""),_T("миллиардов"),_T(""),_T(""),_T("триллионов")},
        {_T(""),_T(""),_T(""),_T("тысяч"), _T(""),_T(""),_T("миллионов"),_T(""),_T(""),_T("миллиардов"),_T(""),_T(""),_T("триллионов")},
        {_T(""),_T(""),_T(""),_T("тысяч"), _T(""),_T(""),_T("миллионов"),_T(""),_T(""),_T("миллиардов"),_T(""),_T(""),_T("триллионов")}
    };

    CText dec[10] = { _T("десять"),_T("одиннадцать"),_T("двенадцать"),_T("тринадцать"),_T("четырнадцать"),_T("пятнадцать"),_T("шестнадцать"),_T("семнадцать"),_T("восемнадцать"),_T("девятнадцать") };
    CText result;

    if (!numb)
    {
        result = _T("ноль");
        return result;
    }
    long long int n1 = numb;
    long long int cnt = 0;

    //подсчет количесива цифр в числе
    while (numb)
    {
        numb /= 10;
        ++cnt;
    }
    long long int celoe = 0;

    //перевод
    while (n1)
    {
        if (!((cnt + 1) % 3))
        {
            if ((n1 / osn[cnt]) == 1)
            {
                n1 %= osn[cnt];
                --cnt;
                celoe = n1 / osn[cnt];
                n1 %= osn[cnt];
                result += dec[celoe];
                --cnt;
                if (!(cnt % 3))
                {
                    result = result + _T(" ");
                    result = result + termination[0][cnt];
                    result = result + _T(" ");                    
                }
            }
            if (!cnt) break;
        }
        celoe = n1 / osn[cnt];
        n1 %= osn[cnt];
        result = result + basis[(cnt-6)%3+6][celoe];
        result = result +_T(" ");
        --cnt;
        if (!(cnt % 3))
        {
            result = result + termination[celoe][cnt];
            result = result + _T(" ");
        }
    }

    return result;
}
// --------------------------
// Задаем падеж
// --------------------------
CText toCase(CText str,CText Case)
{
    CText res;
    std::vector<CText> strs;
    str.collectWords(strs);
    Numerals n;
    Multipliers m;

    std::vector<CText> result;
    CText frm = CText(_T("м"))+Case;
    for (int i = strs.size() - 1; i >= 0; --i)
    {
        auto w = strs[i];
        CText mul = m.getWordInCase(w, Case);
        if (!mul.isEmpty())
        {
            result.push_back(mul);
            if (w == _T("тысяч") || w == _T("тысяча") || w == _T("тысячи"))
            {
                frm = CText(_T("ж"))+Case;
                continue;
            }
            else
            {
                frm = CText(_T("м"))+Case;
                continue;
            }
        }

        CText num;

        num = n.getWordInCase(w, frm);
        if (!num.isEmpty())
        {
            result.push_back(num);
        }

    }
    std::reverse(result.begin(), result.end());
    
    frm = CText(_T("м")) + Case;
    for (auto& w : result)
    {
        int v = n.getValue(w);
        if (v == 1)
        {
            frm = CText(_T("е")) + Case;
        }
        if (v > 1 && v<5)
        {
            frm = CText(_T("ч")) + Case;
        }
        if (v >= 5)
        {
            frm = CText(_T("м")) + Case;
        }
        if (m.getValue(w) != -1)
        {
            CText mul = m.getWordInCase(w, frm);
            w = mul;
        }
       
    }

    for (auto w : result)
    {
        res = res + w;
        res = res + _T(" ");
        //std::wcout << w << std::endl;
    }
    res.trim();
    return res;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF8");
    std::locale::global(std::locale("ru_RU.UTF8"));
    
    long long int x = 126456780091313;

    CText str;    
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    std::wcout << _T("Исходное число: ") << x << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    str=towords(x);
    std::wcout << _T("Число прописью: ") << str << std::endl;    
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    x = str2num(str);
    std::wcout << _T("число из прописного: ") << x << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    std::wcout << _T("Изменение по падежам") << std::endl;
    std::wcout << _T("ПАДЕЖ        ВОПРОС                  ПРЕДЛОГИ") << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    std::wcout << _T("Именительный (есть)кто? что?         -") << std::endl;
    std::wcout << toCase(str, _T("ип")) << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    std::wcout << _T("Родительный  (нет)кого? чего?        с, у, от, до, из, без, для, вокруг, около, возле, кроме") << std::endl;
    std::wcout << toCase(str, _T("рп")) << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    std::wcout << _T("Дательный    (дать)кому? чему?       к, по, благодаря, вопреки, согласно") << std::endl;
    std::wcout << toCase(str, _T("дп")) << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    std::wcout << _T("Винительный  (вижу)кого? что?        под, за, про, через, в, на, во") << std::endl;
    std::wcout << toCase(str, _T("вп")) << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    std::wcout << _T("Творительный (доволен)кем? чем?      с, со, за, над, под, между, перед") << std::endl;
    std::wcout << toCase(str, _T("тп")) << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;
    std::wcout << _T("Предложный   (думать)о ком? о чем?   в, о, об, на, при, по") << std::endl;
    std::wcout << toCase(str, _T("пп")) << std::endl;
    std::wcout << _T("--------------------------------------------------------------------------------------------") << std::endl;

    return 0;
}

