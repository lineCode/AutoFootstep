# AutoFootstep

## Setup

### 1. Open Modifiers Window

Open an animation sequence or skeleton to which you want to add footstep animation notifies or sync markers, and then open the **Animation Data Modifiers** window.

![AutoFootstep_Readme_01](https://github.com/suramaru517/AutoFootstep/assets/50897830/47e5e194-0679-4e49-995a-3b12876956f9)

### 2. Add Modifier

Add **AutoFootstepAnimationModifier** and set its properties.

<details>
 <summary>Property Description</summary>

 * Path Filters
   * If the array is not empty, apply the modifier only to animations whose paths contain any of the strings in the array. This is useful when applying the modifier to a skeleton.
 * Foot Bone Names
   * Names of the foot bones to detect footsteps.
 * Notify
   * Add Notify
     * If true, add animation notifies to the footstep frames.
   * Notify Class
     * Animation notify class to add. The default is AutoFootstepAnimNotify.
   * Notify Params
     * Parameters to pass to the animation notifies. Valid only if the Notify Class is AutoFootstepAnimNotify.
   * Notify Track Name
     * Name of the notify track to which animation notifies will be added.
 * Sync Marker
   * Add Sync Marker
     * If true, add sync markers to the footstep frames.
   * Marker Names by Foot Bone
     * Names of the sync markers for each foot bone.
   * Marker Track Name
     * Name of the notify track to which synch markers will be added.
 * Advanced
   * Frame Rate Override
     * The frame rate to use for detecting footstep frames. If false, the animation frame rate is used. Higher values will give more accurate results.
   * Ground Height Range
     * The higher the value, the coarser the footstep detection. If unnecessary footsteps are detected, increase the value.
   * Grounded Threshold
     * The higher the value, the coarser the footstep detection. If the footstep frames are shifted, increase the value.
   * Add Curves Of Location Z
     * If true, add curves of the foot bone location Z used to detect footsteps.

</details>

<details>
 <summary>AutoFootstepAnimNotifyを使用する場合</summary>

 1. プロジェクト設定で表面タイプを定義します。

    ![AutoFootstep_Readme_11](https://github.com/suramaru517/AutoFootstep/assets/50897830/467e3782-7ad3-4f28-95f5-81db1b708e04)

 2. DataAssetを作成します。

    ![AutoFootstep_Readme_03](https://github.com/suramaru517/AutoFootstep/assets/50897830/e2653b4a-c055-4f84-926d-d48bed6c861a)

 3. AutoFootstepEffectContextを選択します。

    ![AutoFootstep_Readme_04](https://github.com/suramaru517/AutoFootstep/assets/50897830/08c41b4c-fc24-4b4b-a3e6-c755e7fd42ff)

 4. 作成したDataAssetを開き、各表面タイプに対応するエフェクトを定義します。AddAllSurfaceTypeElementsボタンを押すと、全ての表面タイプをキーに持つ要素が自動的に追加されます。

    ![AutoFootstep_Gallery_05](https://github.com/suramaru517/AutoFootstep/assets/50897830/cb93c67e-8e63-46e4-af57-958ea0347ff4)

 5. 物理マテリアルを定義した表面タイプの数分作成します。

    ![AutoFootstep_Readme_06](https://github.com/suramaru517/AutoFootstep/assets/50897830/86029c45-ecd3-462a-af43-b5ebbc1c5f55)

 6. 作成した物理マテリアルを開き、それぞれに異なる表面タイプを設定します。

    ![AutoFootstep_Readme_09](https://github.com/suramaru517/AutoFootstep/assets/50897830/493638f7-b533-4174-8766-aa6cb78535f7)

 7. 足音のエフェクトを変えたい床などのメッシュに作成した物理マテリアルを設定します。物理マテリアルはマテリアルに設定することもできます。

    ![AutoFootstep_Readme_10](https://github.com/suramaru517/AutoFootstep/assets/50897830/c6b8058f-bd7d-4743-a692-4f41b8171019)

</details>

![AutoFootstep_Gallery_03](https://github.com/suramaru517/AutoFootstep/assets/50897830/6a37f275-f141-4f35-abb5-0892b05bce12)

### 3. Apply Modifier

Apply AutoFootstepAnimationModifier to automatically add animation notifies or sync markers to footstep frames.

![AutoFootstep_Success](https://github.com/suramaru517/AutoFootstep/assets/50897830/cb7b7de2-e806-4164-a362-bba693ac2d07)

## Tips

### カスタムのアニメ通知を使用する

AutoFootstepAnimationModifierを継承し、OnNotifyAddedをオーバライドすることで、アニメ通知が追加される際に渡すパラメータを制御できます。

![AutoFootstep_OnNotifyAdded](https://github.com/suramaru517/AutoFootstep/assets/50897830/d891fc2a-99c2-412b-bc3f-ff01fca9d181)

### 手動で足音エフェクトを再生する

AutoFootstepEffectContextのPlayEffectBySurfaceTypeを使用できます。

![AutoFootstep_PlayEffectBySurfaceType](https://github.com/suramaru517/AutoFootstep/assets/50897830/abf36307-ae3a-45bf-85af-1a3e8df52ed5)

