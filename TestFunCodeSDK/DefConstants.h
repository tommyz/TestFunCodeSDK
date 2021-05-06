//
//  DefConstants.h
//  InvoiceMonster
//
//  Created by tommy su on 2018/10/3.
//  Copyright © 2018 Friendo. All rights reserved.
//

#ifndef DefConstants_h
#define DefConstants_h

#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

//設定UserDefault的值
#define SetUserValue(value,key) [[NSUserDefaults standardUserDefaults] setValue:value forKey:key]
//獲取UserDefault的值
#define GetUserValue(key)  [[NSUserDefaults standardUserDefaults] valueForKey:key]

#pragma mark - Color

#define ZXColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]

#define ZXColorRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]

#pragma mark - API

//UAT           kUAT為1時不理會kDebugTest的值，通常給PM測試
//Apple Store   為kUat跟kDebugTest都為0
//Dev = INT     為kUat=0 跟 kDebugTest=1
#define kUat 0
#define kDebugTest 1
#define kTommy 1
#define kAka 0
#define kDora 0

#define kPhotoDeviceSettingTag 1005

#define kScreenScale [[UIScreen mainScreen] scale]

#define SuiteName @"group.com.tw.FriendoLoyaltyCards"

#define kApiAuthorizationKey @"X2ZyaWVuZG9fbWVtYmVyX2NhcmRf"

#define kApiVersion @"/v1"

#pragma mark Tommy
#define kTommyPhone @"0928828895"
#define kTommyMemberId (kUat ? @"a663046c-10a6-42bc-9780-5671c7780eb2" : (kDebugTest ? @"cae23b09-0e82-4d9f-932d-3de9a16c5545" : @"a663046c-10a6-42bc-9780-5671c7780eb2"))

#pragma mark Phoebe
//#define kTommyPhone @"0958808289"
//#define kTommyMemberId (kUat ? @"a4e1ae8a-92b6-402b-bf55-0506d503ee0c" : (kDebugTest ? @"a4e1ae8a-92b6-402b-bf55-0506d503ee0c" : @"a4e1ae8a-92b6-402b-bf55-0506d503ee0c"))

//筱筑UAT
//0988139917
//e135d29e-70e6-47d1-8a17-a7d880a76752

//小岑正式機
//0ec5b97f-b332-4952-8157-0de2c52743fa
//#define kTommyMemberId (kUat ? @"0ec5b97f-b332-4952-8157-0de2c52743fa" : (kDebugTest ? @"cae23b09-0e82-4d9f-932d-3de9a16c5545" : @"0ec5b97f-b332-4952-8157-0de2c52743fa"))

#pragma mark Aka
#define kAkaPhone @"0935721740"
#define kAkaMemberId (kUat ? @"ef6b3467-c05a-4965-8ce5-815873e8229d" : (kDebugTest ? @"558d984c-9d9c-4499-86cf-86d2203c869d" : @"ef6b3467-c05a-4965-8ce5-815873e8229d"))

#pragma mark Dora 整合跟UAT會員id為正確，其他不確定
//iPhone測試帳號
#define kDoraPhone @"0999999031"
#define kDoraMemberId (kUat ? @"7fb04586-b9a7-4f27-88b4-4a5aefd60e60" : (kDebugTest ? @"14a9fda1-8d06-4b4a-afcb-707e39ae797d" : @"7fb04586-b9a7-4f27-88b4-4a5aefd60e60"))
//Android測試帳號
//#define kAkaPhone @"0999999030"
//#define kAkaMemberId (kUat ? @"08eea607-9fdd-4ce1-90af-8158fbcc4d08" : (kDebugTest ? @"deb168f4-a9ef-4d7f-a6a4-f20cbc58d355" : @"7fb04586-b9a7-4f27-88b4-4a5aefd60e60"))

#pragma mark Mio 整合跟UAT會員id為正確，其他不確定
//#define kAkaPhone @"0911272706"
//#define kAkaMemberId (kUat ? @"acc343ea-81d1-4346-8ee5-19c5155e35a3" : (kDebugTest ? @"acc343ea-81d1-4346-8ee5-19c5155e35a3" : @"acc343ea-81d1-4346-8ee5-19c5155e35a3"))

#pragma mark 馬丁 測試機會員id為正確，其他不確定
//#define kAkaPhone @"0955188504"
//#define kAkaMemberId (kUat ? @"53d89315-7e83-438d-abb5-b04c64cfc3a1" : (kDebugTest ? @"53d89315-7e83-438d-abb5-b04c64cfc3a1" : @"53d89315-7e83-438d-abb5-b04c64cfc3a1"))

#pragma mark Apple審核用的
#define kApplePhone @"0900123456"
#define kAppleMemberId @"e865e137-21cf-488e-b66a-85b2de96e30f"

#define kBaseURL (kUat ? @"https://monsterapi-uat.qscan.me" : (kDebugTest ? @"https://api-int.gdcard888.com" : @"https://monsterapi.qscan.me"))

#define kBaseProxyURL (kUat ? @"https://monsterapi-uat.qscan.me" : (kDebugTest ? @"https://api-int.gdcard888.com" : @"https://proxy.monsterapi.qscan.me"))

#define kOauthURL (kUat ? @"https://monsteroauth-uat.qscan.me" : (kDebugTest ? @"https://oauth-int.gdcard888.com" : @"https://monsteroauth.qscan.me"))
#define kT2URL (kUat ? @"https://monsterapi-tp-uat.qscan.me" : (kDebugTest ? @"https://tp.api-int.gdcard888.com" : @"https://monsterapi-tp.qscan.me"))

//小岑測試版本
//正式機http://13.230.189.91:8080
//#define kBaseURL (kUat ? @"https://monsterapi-uat.qscan.me" : (kDebugTest ? @"https://api-int.gdcard888.com" : @"http://13.230.189.91:8080"))
//#define kOauthURL (kUat ? @"https://oauth-int.gdcard888.com" : (kDebugTest ? @"https://oauth-int.gdcard888.com" : @"https://monsteroauth.qscan.me"))
//#define kT2URL (kUat ? @"http://34.80.36.27:8080" : (kDebugTest ? @"https://tp.api-int.gdcard888.com" : @"https://monsterapi-tp.qscan.me"))

//mio測試版本
//正式機http://192.168.30.113

#define kBaseOAuthorization (kDebugTest ? @"Basic ZWY4OTliNDk3ZmE1NjM1NzNjMDYyMzRhYmE2ZDc3MDY6ZmI0M2IwZDA4MDc0YjNjN2IxYjU0MWVlYjliMzQxMWY=" : @"Basic ZWY4OTliNDk3ZmE1NjM1NzNjMDYyMzRhYmE2ZDc3MDY6ZmI0M2IwZDA4MDc0YjNjN2IxYjU0MWVlYjliMzQxMWY=")


#define kOauthToken @"/token"
#define kOauthInfo @"/info"

#define kInvoiceTimeoutInterval 20.0f
#define kBuyTimeoutInterval 10.0f
#define kErrorCode5000 @"Q呆又在搗亂了…我們正在制止它\n，請稍候再試～"
#define kFailureErrorTimedOut @"Q摸發現網路怪怪的唷，請稍候再試～"
#define kFailureErrorTimedOutBuy @"目前網路擁塞，若購買成功會立即推播通知主人><"
#define kFailureErrorTimedOutRegisterCarrier @"載具相關服務無法正常運作，請稍後再試～"
#define kFailureErrorTimedOutInvoice @"咦，主人的發票資料未更新成功，請稍後再試～"
#define kFailureWebViewUrl @"網頁無法載入"

#define kSyncTitle @"同步成功"
#define kSyncMessage @"店家上傳發票資訊至財政部通常需要48小時之作業時間，此依財政部提供之最新資料為主"
#define kSyncBusyMessage @"財政部資料庫忙碌中，請稍後再試QQ"

#define kOatuhTokenTitle @"系統提示"
//#define kOatuhTokenTitle @"Oatuh系統提示"
#define kOatuhTokenMessage @"請輸入手機號碼重新登入"
//#define kOatuhTimeoutInterval 3.0f

#pragma mark - monster

#define kMonsterGetMonsterAnimation @"/monster/GetMonsterAnimation/"
#define kMonsterGetMonsterAnimation2 @"/monster/GetMonsterAnimation2/"
#define kMonsterGetMonsterAnimation3 @"/monster/GetMonsterAnimation3/"
#pragma mark - invoice

//(2.1) > 發票掃描
//#define kInvoiceScanInvoiceQR @"/invoice/scanInvoiceQR"
//#define kInvoiceScanInvoiceQR2 @"/invoice/scanInvoiceQR2"
#define kInvoiceScanInvoiceQR2_2 @"/invoice/scanInvoiceQR2_2"
//傳統發票掃描，回傳怪獸動畫
#define kInvoiceScanTraditionInvoice @"/invoice/scanTraditionInvoice"

//取得特定發票明細，當會員點「發票清單」的某張發票時呼叫
#define kInvoiceGetInvoiceDetail @"/invoice/getInvoiceDetail"
//刪除會員發票
//#define kInvoiceDeleteMemberInvoice @"/invoice/deleteMemberInvoice"
#define kInvoiceDeleteMemberInvoiceV2 @"/invoice/deleteMemberInvoiceV2"
//(2.2) > 手動輸入發票
#define kInvoiceInvoiceManualInput @"/invoice/invoiceManualInput"
//手動輸入傳統發票
#define kInvoiceTraditionInvoiceManualInput @"/invoice/traditionInvoiceManualInput"
//取得註冊手機條碼的驗證圖案
#define kInvoiceGetCarrierRegisterImageCode @"/invoice/getCarrierRegisterImageCode"
//(4.1) > 發票手機條碼登入
#define kInvoiceVehicleLogin @"/invoice/vehicleLogin"
#define kInvoiceCarrierLogin @"/invoice/carrierLogin"
//(4.1) > 更新手機條碼的驗證碼
#define kInvoiceUpdateCardEncrypt @"/invoice/updateCardEncrypt"

//(4.4) > 會員載具清單
#define kInvoiceMemberCarrierCards @"/invoice/memberCarrierCards"
//(4.2) > 發票手機條碼解除
#define kInvoiceCarrierRelease @"/invoice/carrierRelease"
//註冊手機條碼
#define kInvoiceRegisterCarrier @"/invoice/registerCarrier"

#define kInvoiceActivityCategory @"/invoice/activityCategory"

//(3.1) > 任務清單
#define kInvoiceActivityList @"/invoice/activityList"
#define kInvoiceActivityListV2 @"/invoice/activityListV2"
//任務列別清單
#define kInvoiceActivityListV3 @"/invoice/activityListV3"
//(3.2) > 任務說明頁
#define kInvoiceActivityDescription @"/invoice/activityDescription"
//(5.1) > 廣告欄位
#define kInvoiceGetBannerV2 @"/invoice/getBannerV2"
//蓋板廣告下次不再看
#define kInvoiceCoverAdsNotShowNextTime @"/invoice/coverAdsNotShowNextTime"
//取得發票中獎清單（有效）
#define kInvoiceGetWinningListLastThreeDigits @"/invoice/getWinningListLastThreeDigits"
//取得會員某一期別中獎發票
#define kInvoiceMemberCarrierInvoiceNotice @"/invoice/memberCarrierInvoiceNotice"
#define kInvoiceMemberActCompleteList @"/invoice/memberActCompleteList"
//任務完成發票清單
#define kInvoiceActCompleteInvoiceList @"/invoice/actCompleteInvoiceList"


// 取得捐贈碼清單
#define kInvoiceGetLoveCodeList @"/invoice/getLoveCodeList"


//通知發廣告獎金
#define kMissionGiveMovieBonus @"/mission/giveMovieBonus"

#pragma mark - collect
//紀錄開啟推撥
#define kCollectRecordOpenedPushingNotify @"/collect/recordOpenedPushingNotify"


#pragma mark - member

//會員註冊
#define kMemberRegister @"/member/register"
//確認驗證碼
#define kMemberVerifyCode @"/member/verifyCode"
//儲存個人資訊
#define kMemberSavePersonalData @"/member/savePersonalData"
//取得會員的怪獸資料
#define kMemberGetMonsterInfo @"/member/getMonsterInfo"
//取得我的頁面資料
#define kMemberGetMyPageInfo @"/member/getMyPageInfo"
//切換怪獸
#define kMemberSwitchMonster @"/member/switchMonster"
//確認蛋蛋
#define kMemberConfirmEgg @"/member/confirmEgg"
//取得蛋蛋列表(未選擇)
#define kMemberGetNotConfirmedEggs @"/member/getNotConfirmedEggs"
//怪獸孵化&切換
#define kMemberHatchMonster @"/member/hatchMonster"
//更新會員怪獸名稱
#define kMemberUpdateMonsterNickname @"/member/updateMonsterNickname"
//會員資料重置
#define kMemberResetInfo @"/member/resetInfo"


//取得怪獸小日子清單
#define kMemberGetMonsterMemoryList @"/member/getMonsterMemoryList"
//取得怪獸明信片清單
#define kMemberGetPostcardList @"/member/getPostcardList"
//取得怪獸明信片內容
#define kMemberGetPostcardContent @"/member/getPostcardContent"
//取得怪獸強運卡清單
#define kMemberGetBlessingCardList @"/member/getBlessingCardList"
//取得怪獸強運卡內容
#define kMemberGetBlessingCardContent @"/member/getBlessingCardContent"
//取得未看的（怪獸明信片、怪獸強運卡）
#define kMemberGetUnreadMemoryCardList @"/member/getUnreadMemoryCardList"
//確認怪獸明信片已看
#define kMemberReadPostcard @"/member/readPostcard"
//確認怪獸強運卡已看
#define kMemberReadBlessingCard @"/member/readBlessingCard"
//取得怪獸記憶清單
#define kMemberGetMemoryList @"/member/getMemoryList"
//取得怪獸記憶碎片清單
#define kMemberGetMemoryPieceList @"/member/getMemoryPieceList"
//選擇怪獸記憶選項
#define kMemberChooseMemoryOption @"/member/chooseMemoryOption"
//取得未看的記憶碎片(同時確認碎片已看)
#define kMemberGetUnreadMemoryPieceList @"/member/getUnreadMemoryPieceList"


//我的禮物盒-是否顯示禮物盒icon
#define kMemberIsShowGiftIcon @"/member/isShowGiftIcon"
//我的禮物盒-取得禮物清單
#define kMemberGetGiftList @"/member/getGiftList"
//我的禮物盒-取得導引任務清單
#define kMemberGetGuideMissionList @"/member/getGuideMissionList"
//我的禮物盒-取得第二段導引任務資料
#define kMemberGetSecondGuideMissionInfo @"/member/getSecondGuideMissionInfo"
//我的禮物盒-接受引導給幣
#define kMemberGiveCoinByGuide @"/member/giveCoinByGuide"


//取得刮刮卡清單
#define kMemberGetCardList @"/member/getCardList"
//打開刮刮卡
#define kMemberOpenScratch @"/member/openScratch"


//取得摸彩券寶箱清單
#define kMemberGetLotteryBoxList @"/member/getLotteryBoxList"
//打開摸彩券寶箱
#define kMemberOpenLotteryBox @"/member/openLotteryBox"
//取得摸彩券開獎通知清單
#define kMemberGetLotteryDrawingNoticeList @"/member/getLotteryDrawingNoticeList"


//取得抽獎券通知資料
#define kMemberGetRaffleNotifyData @"/member/getRaffleNotifyData"
//取得抽獎券開獎通知資料
#define kMemberGetRaffleDrawingNotifyData @"/member/getRaffleDrawingNotifyData"
//取得抽獎券清單
#define kMemberGetRaffleList @"/member/getRaffleList"
//取得抽獎券明細
#define kMemberGetRaffleDetail @"/member/getRaffleDetail"


//取得寶箱清單
#define kMemberGetBoxList @"/member/getBoxList"
//(3.2) 取得會員的寶箱獎項
#define kMemberBoxOpenBox @"/member/box/OpenBox"
//取得會員發票清單
#define kMemberGetMemberInvoiceList @"/member/getMemberInvoiceList"
#define kMemberGetMemberInvoiceList2 @"/member/getMemberInvoiceList_v2"
//取得會員的兌換券清單
#define kMemberGetVoucherList @"/member/getVoucherList"
//取得會員的兌換券明細
#define kMemberGetVoucherDetail @"/member/getVoucherDetail"
//取得縣市區資料
#define kMemberGetCountyDistrictList @"/member/getCountyDistrictList"
//更新兌換券地址
#define kMemberUpdateVoucherAddress @"/member/updateVoucherAddress"
//取得會員的碎片清單
#define kMemberGetPieceList @"/member/getPieceList"
//取得會員的碎片說明頁
#define kMemberGetPieceDetail @"/member/getPieceDetail"
//取得全家條碼
#define kMemberGetFamilyPincode @"/member/getFamilyPincode"
//取得萊爾富條碼
#define kMemberGetHilifePincode @"/member/getHilifePincode"
//取得7-11條碼
#define kMemberGetSevenPincodeUrl @"/member/getSevenPincodeUrl"
//取得宜睿條碼
#define kMemberGetEdenredPincodeUrl @"/member/getEdenredPincodeUrl"
//取得取得條碼
#define kMemberGetPincode @"/member/getPincode"
//更新裝置Token
#define kMemberUpdateDeviceToken @"/member/updateDeviceToken"
//版本控管
#define kMemberCheckVersion @"/member/checkVersion"
//取得意見回饋清單
#define kMemberGetFeedbackList @"/member/getFeedbackList"
//意見回饋
#define kMemberFeedback @"/member/feedback"
//取得會員某一期別中獎發票
#define kMemberGetWinningInvoicesByPeriod @"/member/getWinningInvoicesByPeriod"
//取得怪獸圖鑑的怪獸清單
#define kMemberGetMonsterListInShowroom @"/member/getMonsterListInShowroom"
//取得怪獸圖鑑清單
#define kMemberGetAnimationListInShowroom @"/member/getAnimationListInShowroom"
//開獎日發票報告
#define kMemberInvoiceWinningReport @"/member/invoiceWinningReport"
//由前端幫會員開獎, 會員進入發票清單頁時，如回傳<由前端開獎>, 則呼叫此 api 即時開獎
#define kMemberAppDrawMemberInvoices @"/member/appDrawMemberInvoices"


//取得怪獸幣展延資訊
#define kMemberGetMonsterCoinExtendInfo @"/member/getMonsterCoinExtendInfo"
//確認展延怪獸幣
#define kMemberExtendMonsterCoin @"/member/extendMonsterCoin"


//取得打卡活動相關資料
#define kMemberGetCheckInActInfo @"/member/getCheckInActInfo"
//打卡
#define kMissionCheckIn @"/mission/checkIn"


//銀行代表列表
#define kMemberGetBankCodeList @"/member/getBankCodeList"
//設定匯款帳戶
#define kMemberBindBankToCardNo @"/member/bindBankToCardNo"
//手機條碼註冊(不需image code)
#define kMemberRegisterCarrierWithoutCode @"/member/registerCarrierWithoutCode"
//登入手機條碼載具(用手機號碼)
#define kMemberRegisterCarrierLoginByCell @"/member/carrierLoginByCell"


//取得載具卡別清單
#define kMemberGetCarrierCardTypeList @"/member/getCarrierCardTypeList"
//同步會員載具發票
#define kMemberSyncMemberVehicleInvoice @"/member/SyncMemberVehicleInvoice"
//卡片歸戶(不需image code)
#define kMemberBindCarrierWithoutCode @"/member/bindCarrierWithoutCode"


#pragma mark - 怪獸養奴隸
//取得怪獸養奴隸首頁資訊
#define kMemberGetMonsterSlaveInfo @"/member/getMonsterSlaveInfo"
//建立假奴隸
#define kMemberCreateDummySlave @"/member/createDummySlave"
//會員狀態
#define kMemberGetMemberSlaveMissionStatus @"/member/getMemberSlaveMissionStatus"
//取得奴隸貢獻點數
#define kMemberGetMemberSlavePoint @"/member/getMemberSlavePoint"
//綁定奴隸(棄用)
#define kMemberBindMemberSlave @"/member/bindMemberSlave"


#pragma mark - 怪獸養奴隸V2
//取得奴隸列表
#define kMemberGetMonsterSlaveList @"/member/getMonsterSlaveList"
//取得奴隸內頁
#define kMemberGetMonsterSlaveInfoV2 @"/member/getMonsterSlaveInfoV2"
//鞭打奴隸資訊
#define kMemberGetSpurMonsterSlaveInfo @"/member/getSpurMonsterSlaveInfo"
//執行鞭打奴隸
#define kMemberSpurMonsterSlave @"/member/spurMonsterSlave"
//更新奴隸名稱
#define kMemberUpdateMonsterSlaveName @"/member/updateMonsterSlaveName"
//一次領取所有奴隸怪獸幣
#define kMemberGetAllMonsterSlavePoint @"/member/getAllMonsterSlavePoint"
//取得奴隸邀請碼
#define kMemberGetMonsterSlaveInviteCode @"/member/getMonsterSlaveInviteCode"
//邀請碼驗證
#define kMemberInviteCodeVerify @"/member/inviteCodeVerify"
//怪獸養奴隸-產生DeepLink
#define kMemberGetDeepLinkUrl @"/member/getDeepLinkUrl"


#pragma mark - Mobile
//T2 > 即時驗證
#define kMobileInputQrcodeInvoice @"/mobile/inputQrcodeInvoice"


#pragma mark - Mission
//Get Movie Ticket
#define kMissionGetMovieTicket @"/mission/getMovieTicket"
//Get Movie Token
#define kMissionGetMovieToken @"/mission/getMovieToken"


#pragma mark - Store
//取得商城控制參數
#define kStoreGetStoreControlDetail @"/store/getStoreControlDetail"
//取得商城首頁 分類列表
#define kStoreGetStoreCategoryList @"/store/getStoreCategoryList"
//商城清單
#define kStoreGetStoreList @"/store/getStoreList"
//商城清單v2
#define kStoreGetStoreListV2 @"/store/getStoreList_v2"
//商城清單v3
#define kStoreGetStoreListV3 @"/store/getStoreListV3"
//取得Line商城搜尋清單
#define kStoreGetLineStoreSearchList @"/store/getLineStoreSearchList"
//Line商城紀錄會員點擊商品
#define kStoreKeepLineStoreProductClicked @"/store/keepLineStoreProductClicked"
//商城明細
#define kStoreGetCommodityDetail @"/store/getCommodityDetail"
//怪獸商城購買
#define kStoreBuy @"/store/buy"
//內購商品iOS
#define kStoreInAppPurchaseIos @"/store/inAppPurchaseIos"
//確認是否可以購買此商品
#define kStoreIsCommodityPurchasable @"/store/isCommodityPurchasable"
//取得抽獎的中獎清單
#define kStoreGetWinnerList @"/store/getWinnerList"
#define kStoreGetWinnerListV2 @"/store/getWinnerListV2"
//取得詳細中獎人列表
#define kStoreGetWinnerDetail @"/store/getWinnerDetail"
//商城兌獎紀錄頁面
#define kStoreGetMemberRedemptionRecord @"/store/getMemberRedemptionRecord"
//時間格式
#define kDateFormat1 @"yyyy-MM-dd'T'HH:mm:ss Z"
#define kDateFormat2 @"yyyy-MM-dd'T'HH:mm:ss'Z'"
#define kDateFormat3 @"yyyy-MM-dd"
#define kUserBirthdayFormat @"yyyy/MM/dd"
#define kUserBirthdayFormatApi @"yyyy-MM-dd"


#pragma mark - Guess
//取得猜猜列表資料
#define kGuessGuessList @"/guess/guessList"
//取得猜猜內頁資料
#define kGuessGetGuessInfo @"/guess/getGuessInfo"
//下注猜猜
#define kGuessBettingGuess @"/guess/bettingGuess"
//猜猜下注紀錄
#define kGuessGuessRecords @"/guess/getGuessRecords"
#define kGuessGuessRecordsV2 @"/guess/getGuessRecordsV2"
#pragma mark - Image Server
/*
 【Image Server 圖片使用方式】
 api回傳url + 參數
 api回傳url：xxx./display?path=xxx.jpg
 參數：&op=resize&w=400
 ex：http://d20h9x40egpux6.cloudfront.net/display?path=firm/258b47d4-283a-413e-9063-fd61c57c08e2.jpg&op=resize&w=600
 */
//Image Server圖片使用方式
#define kImageServerResize @"resize"
#define kImageServerThumbnail @"thumbnail"
#define kImageServer(url,op,w,h) [NSString stringWithFormat:@"%@&op=%@&w=%.0f&h=%.0f",url,op,w*kScreenScale,h*kScreenScale]

#define kImageServerResizeW(url,op,w) [NSString stringWithFormat:@"%@&op=%@&w=%.0f",url,op,w*kScreenScale]

#define KFAQUrl @"https://qmonster.cc/faq.html"


#endif /* DefConstants_h */
