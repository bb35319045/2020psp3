# 課題3 レポート
学生番号 35319045　氏名 松本聡浩


## 課題  

以下の2つのアルゴリズムで文字列を検索するプログラムを作成する。  
- 力ずく法
- BM法

1. 使用するデータ  
以下のデータを使用する。ただし、検索対象文字列、検索する文字列は変更しても良い。  
    - StrOriginal: 検索対象データ
    - StrKey: 検索する文字列

2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。C言語の標準ライブラリは使用しないこと。  
    (1) ForceSearch: 力ずく法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  

    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

    (2) BMSearch: BM法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  
 
    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

1. 補助関数  
なし

## ソースコードの説明
ForceSearch:
12~15:ForceSearch関数で使う、pos、start、Original_len、Key_lenを0で初期化。
17~19:Original_lenをStrOriginalの文字列の長さに更新。
21~23:Key_lenをStrKeyの文字列の長さに更新。
26,27:keyとtextが一致したらposを1つ進める。
28:keyが'\0'なら&text[start]を返し、ループを抜ける。
32~34:keyの長さ(Key_len)と比較開始位置(start)の和がtext(Original_len)の長さを超えたら、NULLを返しループを抜ける。
35~37:それら以外の時、startを1つ進め、pos=0に初期化。

BMSearch:
45~51:BMSearch関数で使う、Original_index、Key_index、Original_len、Key_lenを0de初期化し、table、for文で使うi、uを定義。
54~56:Original_lenをStrOriginalの文字列の長さに更新。
58~60:Key_lenをStrKeyの文字列の長さに更新。
62~64:tableのすべての要素をkey_lenの値にする。
66~68:keyに含まれる文字をそれぞれ位置によって定義しなおす。
70、71:Original_index、Key_indexを文字列の一番後ろに移動。
75~82:文字が一致した場合の条件
76~78::Key_indexが一番最初に移動していたら、&text[Original_index]を返し、ループを抜ける。
79~82:それ以外ならKey_index、Original_indexを1つ戻す。
83~91:文字が不一致の場合の条件
84~86:Original_indexが文字列の長さを超えたら、NULLを返し、ループを抜ける。
88、89:Original_index、Key_indexの位置を更新

## 出力結果
Force Search. Find keyword at: wind in my hair.
BM Search. Find keyword at: wind in my hair.
## 修正履歴

