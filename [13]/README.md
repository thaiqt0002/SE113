# 4 BÀI TẬP

## Exercise 1 (Run ex1.R file)

[ SEED: 1234 ]

1. いま，バグ予測のためのメトリクスとして LOC を使うことにする．訓練データにおいて，LOC > 30 ならばそのモジュールをバグ有りと予測する場合の再現率を答えなさい．(Suppose we use the metric LOC in our bug prediction activity. Here, we predict a module is buggy if its LOC > 30. Answer the recall value in our training data.) 
**Answer:**  0.6

2. 適合率を答えなさい (Answer the precision value)
**Answer:** 0.193548387096774

3. F 値を答えなさい (Answer the F value)
**Answer:** 0.292682926829268

## Exercise 2 (Run ex2.R file)

[ SEED: 1234 ]

1. メトリクス LOC を使ってバグがありそうなモジュールから順にテストすることを考える．テストデータについて，この方法でテストした場合の効率を答えなさい．(Let us use the metric LOC to predict the bug-proneness of modules and prioritize their tests.
Answer the test efficiency (explained on page 36 of the lecture note); see pages 33--36)
**Answer:** 0.5512195

2. メトリクス CALL を使った場合のテスト効率を答えなさい (Answer the test efficency when we use the metric CALL in the similar way to the above problem)
**Answer:** 0.502439

## Exercise 3 (Run ex3.R file)

1. いま，乱数の種を 9876 としてデータセットの分割をやり直 (p13 参照). そして，訓練データにおいて，CC > 10 ならばそのモジュールをバグ有りと予測する場合の再現率を答えなさい．(Redo the dataset spliting with the random seed 9876. Suppose we predict a module is buggy if its CC > 10. Answer the recall value in the new training data.)
**Answer:** 0.333333333333333

2. 適合率を答えなさい (Answer the precision value)
**Answer:** 0.264705882352941

3. F 値を答えなさい (Answer the F value)
**Answer:** 0.295081967213115

## Exercise 4 (Run ex4.R file)

1. 乱数の種を 9876 に設定し，SMOTEアルゴリズムを使ったロジスティック回帰モデルを作りなさい．そして，それを使ってバグがありそうなモジュールから順にテストすることを考える．テストデータについて，この方法でテストした場合の効率を答えなさい．(Set the random seed as 9876 and build the SMOTE algorithm-baed logistic regression model. Then, we use it to predict the bug-proneness of modules and prioritize their tests.Answer the test efficiency (explained on page 37 of the lecture note); see pages 54--58)
**Answer:** 0.5512195
