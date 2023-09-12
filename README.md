# AutoFootstep

## セットアップ方法

1. 足音のアニメ通知や同期マーカーを追加したいアニメーションシーケンスおよびスケルトンを開き、Animation Data Modifiers タブを表示します。

![AutoFootstep_Readme_01](https://github.com/suramaru517/AutoFootstep/assets/50897830/47e5e194-0679-4e49-995a-3b12876956f9)

2. AutoFootstepAnimationModifierを追加し、プロパティを設定して適用します。

* Path Filters: 配列が空でない場合、指定した文字列をパスに含むアニメーションのみにモディファイアを適用します。これはスケルトンにモディファイアを適用する場合に有用です。
* Foot Bone Names: アニメ通知や同期マーカーを追加する足のボーン。
* Notify
  * Add Notify: 真の場合、足音のフレームにアニメ通知を追加します。
  * Notify Class: 追加するアニメ通知のクラス。デフォルトはAutoFootstepAnimNotifyです。
  * Notify Params: アニメ通知に渡すパラメータ。Notify ClassがAutoFootstepAnimNotifyの時のみ有効です。
  * Notify Track Name: アニメ通知を追加する通知トラックの名前。
* Sync Marker
  * Add Sync Marker: 真の場合、足音のフレームに同期マーカーを追加します。
  * Marker Names by Foot Bone: 足ボーンごとの同期マーカーの名前。
  * Marker Track Name: 同期マーカーを追加する通知トラックの名前。
* Advanced
  * Frame Rate Override
    * 足音のフレームの検出に用いるフレームレート。偽の場合はアニメーションのフレームレートを使用します。値が大きいほど正確な結果が得られます。
  * Ground Height Range
    * 値が大きいほど足音の検出がおおまかになります。余分な足音が検出される場合は、値を大きくしてください。
  * Grounded Threshold
    * 値が大きいほど足音の検出がおおまかになります。足音のフレームがずれる場合は、値を大きくしてください。
  * Add Curves Of Location Z
    * 真の場合、足音の検出に用いた足ボーンの位置Zのカーブを追加します。

![AutoFootstep_Gallery_03](https://github.com/suramaru517/AutoFootstep/assets/50897830/6a37f275-f141-4f35-abb5-0892b05bce12)

<details>
<summary>AutoFootstepAnimNotifyを使用する場合</summary>

2.1. プロジェクト設定で表面タイプを定義します。

![AutoFootstep_Readme_11](https://github.com/suramaru517/AutoFootstep/assets/50897830/467e3782-7ad3-4f28-95f5-81db1b708e04)

2.2. DataAssetを作成します。これはAutoFootstepAnimNotifyを用いる場合に必要です。独自のアニメ通知を用いる場合はスキップします。

![AutoFootstep_Readme_03](https://github.com/suramaru517/AutoFootstep/assets/50897830/e2653b4a-c055-4f84-926d-d48bed6c861a)

2.3. AutoFootstepEffectContextを選択します。

![AutoFootstep_Readme_04](https://github.com/suramaru517/AutoFootstep/assets/50897830/08c41b4c-fc24-4b4b-a3e6-c755e7fd42ff)

2.4. DataAssetに各表面タイプに対応するエフェクトを定義します。AddAllSurfaceTypeElementsボタンを押すと、全ての表面タイプをキーに持つ要素が自動的に追加されます。

![AutoFootstep_Gallery_05](https://github.com/suramaru517/AutoFootstep/assets/50897830/cb93c67e-8e63-46e4-af57-958ea0347ff4)

2.5. q

![AutoFootstep_Readme_06](https://github.com/suramaru517/AutoFootstep/assets/50897830/86029c45-ecd3-462a-af43-b5ebbc1c5f55)

2.6. a  
![AutoFootstep_Readme_08](https://github.com/suramaru517/AutoFootstep/assets/50897830/bc862405-b3fd-4cfb-8a65-e4c2623c4012)

2.7. a

![AutoFootstep_Readme_09](https://github.com/suramaru517/AutoFootstep/assets/50897830/493638f7-b533-4174-8766-aa6cb78535f7)

2.8. a

![AutoFootstep_Readme_10](https://github.com/suramaru517/AutoFootstep/assets/50897830/c6b8058f-bd7d-4743-a692-4f41b8171019)

</details>

4. 成功！

![AutoFootstep_Success](https://github.com/suramaru517/AutoFootstep/assets/50897830/cb7b7de2-e806-4164-a362-bba693ac2d07)

## Tips

### カスタムのアニメ通知を使用する

AutoFootstepAnimationModifierを継承し、OnNotifyAddedをオーバライドすることで、アニメ通知が追加される際に渡すパラメータを制御できます。

![AutoFootstep_OnNotifyAdded](https://github.com/suramaru517/AutoFootstep/assets/50897830/d891fc2a-99c2-412b-bc3f-ff01fca9d181)

### 手動で足音エフェクトを再生する

AutoFootstepEffectContextのPlayEffectBySurfaceTypeを使用できます。

![AutoFootstep_PlayEffectBySurfaceType](https://github.com/suramaru517/AutoFootstep/assets/50897830/abf36307-ae3a-45bf-85af-1a3e8df52ed5)

