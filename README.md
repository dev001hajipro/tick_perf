# 計測と分析



この計算をコンパイル時に済ませてしまうことを**「定数伝播（Constant Propagation）」**と呼ぶ

- Valgrind
- 

## callgrindによる命令数の計測

```
# --tool=callgrind : Callgrindプロファイラを使用
# ./cost_test_O3 : 計測対象の実行ファイル
valgrind --tool=callgrind ./cost_test_O3
```

## サマリーの簡易確認

```
# <pid> の部分は、生成されたファイル名に合わせて変更してください
callgrind_annotate callgrind.out.<pid>
```


行,指標,意味
I,Instructions,実行された命令の総数 (最も重要な Tickコスト 指標)
D1mr,L1データキャッシュのミス数,メモリボトルネックの指標
D2mr,L2データキャッシュのミス数,メモリボトルネックの指標
I1mr,L1命令キャッシュのミス数,コードの流れの複雑性の指標