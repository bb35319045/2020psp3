# 課題5 レポート
学生番号　氏名


## 課題
本課題では、以下の3つのプログラムを作成する。なお、出発駅、到着駅は、適宜変更しても良い。
- 赤迫駅を出発点として、深さ優先探索ですべての駅に到達可能なことを確認するプログラム。到達した駅名を出力するなど、各駅に1回到達したことを確認すること。  
- 赤迫駅を出発点として、幅優先探索ですべての駅に到達可能なことを確認するプログラム。到達した駅名を出力するなど、各駅に1回到達したことを確認すること。  
- 赤迫駅を出発点として、蛍茶屋駅までの最短所要時間ルートをダイクストラ法で見つけ、出力するプログラム
路線図、および、駅間の所要時間は下記のようになっている。  

1.使用するデータ  
路線図、及び、駅間の所要時間は下記のようになっている。なお、プログラムにおいて、駅名はArrayStation、グラフは隣接行列AdjacencyMatrixに保存されている。  

<img src=images/routemap.png width=600>  

```
typedef struct tagStation {
    char name[20];
    char kanji[16];
} Station;

Station ArrayStation[MAX_STATIONS] = {
    {"akasako", "赤迫"},
    {"nagasakidaigakumae", "長崎大学前"},
    {"nagasakiekimae", "長崎駅前"},
    {"shinchichukagai", "新地中華街"},
    {"ishibashi", "石橋"},
    {"sofukuji", "崇福寺"},
    {"shiminkaikan", "市民会館"},
    {"hotarujaya", "蛍茶屋"},
};

int AdjacencyMatrix[MAX_STATIONS][MAX_STATIONS] = {
    {0,  5,  0,  0,  0,  0,  0,  0},
    {5,  0, 16,  0,  0,  0,  0,  0},
    {0, 16,  0,  7,  0,  0,  5,  0},
    {0,  0,  7,  0,  7,  6, 10,  0},
    {0,  0,  0,  7,  0,  0,  0,  0},
    {0,  0,  0,  6,  0,  0, 10,  0},
    {0,  0,  5, 10,  0, 10,  0,  6},
    {0,  0,  0,  0,  0,  0,  6,  0},
};
```


2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
(1) DepthFirstSearch: 深さ優先探索ですべての駅に到達可能なことを確認する  
    [入力]
    - int size: 駅の数　　
    - int matrix[size][size]: 隣接行列
    - int start: 出発駅のインデックス  

    [出力]  
    - なし。関数の出力はないが、関数内でprintf文を使うなど、すべての駅に到達可能なことをチェックすること。  


    (2) BreadthFirstSearch: 幅優先探索ですべての駅に到達可能なことを確認する  
    [入力]
    - int size: 駅の数　　
    - int matrix[size][size]: 隣接行列
    - int start: 出発駅のインデックス  

    [出力]  
    - なし。関数の出力はないが、関数内でprintf文を使うなど、すべての駅に到達可能なことをチェックすること。


3. 補助関数  
以下の関数はすでに実装されており、利用することができる。
- PrintStationName: indexで指定される駅名を出力する
- StackInit: スタックを初期化する
- StackPush: スタックに値をプッシュする
- StackPop: スタックから値をポップする
- StackTop: スタックの先頭の値を取得する(スタックポインタは移動しない)
- StackIsEmpty: スタックが空か判断する。空の場合はTRUE、空でなければFALSEを返す。
- InitQueue: キューを初期化する
- EnQueue: キューに値を入れる
- DeQueue: キューから値を取り出す
- QueueIsEmpty: キューが空か判断する。空の場合はTRUE、空でなければFALSEを返す。
- main: メイン関数。深さ優先探索、幅優先探索、ダイクストラ法による最短経路探索処理を呼び出す。

4. チャレンジ課題  
    (1) 赤迫駅を起点として、各駅にたどり着くまでのルートを、深さ優先探索、幅優先探索のそれぞれの場合で出力するようにプログラムを修正する。  
   - 深さ優先探索のルート表示(10点)
   - 幅優先探索のルート表示(10点)

    (2) SearchGraphByDijkstra: ダイクストラ法で、出発駅から到着駅までの最短所要時間ルートを探索する(20点)。  
    [入力]  
    - int start: 出発駅のインデックス
    - int goal: 到着駅のインデックス  
    - int size: 駅数  
    - int matrix[size][size]: 隣接行列  
    - NodeInfo arrayNodeInfo[size]:  

    [出力]  
    - return値: 出発駅から到着駅までの所要時間 
    - 関数内でprintf文を使い、最短ルートを出力すること


## ソースコードの説明
115~117:visitedの値を初期化
120:SPを初期化
121:出発地をpush
125:stackの一番上に入っている値をpopし、Stack_tmpに代入
127:visited[Stack_tmp]の値によって条件分岐
128:popされた値を一時的にindex_tmpで記憶しておく
130,131: visited[Stack_tmp] = 1に更新し、その場所を表示する
133~139:今のindexから行ける場所をpush

210~212:visitedの値を初期化
215:キューを初期化(QueueInit)
216:出発点をキューに⼊れる
220:出発地をキューから取り出し
222:visited[Queue_tmp]の値によって条件分岐
223:キューから取り出した値を一時的にindex_tmpで記憶しておく
225,226: visited[Queue_tmp] = 1に更新し、その場所を表示する
228~234:今のindexから行ける場所をキューに入れる

247~250:costとfixedを9999、0に初期化
252:startの位置のcostを0に更新
257~264:costがminより小さい場合minを更新しそのindexも記憶
266:一番小さい値のindexのfixedを1に更新
269~272:goalまでこうしんできたらループから抜ける
275~283:現在のindexから行けるところを見つけ最短になるようにcostを更新する





## 出力結果
DepthFirstSearch:
赤迫
長崎大学前
長崎駅前
市民会館
蛍茶屋
崇福寺
新地中華街
石橋

BreadthFirstSearch:
赤迫
長崎大学前
長崎駅前
新地中華街
市民会館
石橋
崇福寺
蛍茶屋

Time Required: 32

## 修正履歴

