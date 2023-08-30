
#include "pch.h"
#include "webview.h"



#ifdef __cplusplus
extern "C" {
#endif

	WEBVIEW_API webview_t webview_createW(int hWnd, wchar_t* userDataFolder, wchar_t* browserExecutableFolder, wchar_t* options) {
		HWND hwnd = (HWND)hWnd;
		webview_t w = webview_create(0, &hwnd, userDataFolder, browserExecutableFolder, options);
		return w;
	}

	//添加主机对象
	WEBVIEW_API void webview_addHostObjectToScript(webview_t w, char* name, VARIANT* object) {
		static_cast<webview::webview*>(w)->addHostObjectToScript(name, object);
	}

	//删除主机对象
	WEBVIEW_API void webview_removeHostObjectFromScript(webview_t w, char* name) {
		static_cast<webview::webview*>(w)->removeHostObjectFromScript(name);
	}

	//打开开发者工具
	WEBVIEW_API void webview_openDevToolsWindow(webview_t w) {
		static_cast<webview::webview*>(w)->openDevToolsWindow();
	}


	//添加title变化回调
	WEBVIEW_API int webview_addDocumentTitleChanged(webview_t w, void(__stdcall* func)(wchar_t*)) {
		return static_cast<webview::webview*>(w)->addDocumentTitleChanged(func);
	}

	//删除title变化回调
	WEBVIEW_API void webview_removeDocumentTitleChanged(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removeDocumentTitleChanged(index);
	}

	//获取页面标题
	WEBVIEW_API wchar_t* webview_getDocumentTitle(webview_t w) {
		return static_cast<webview::webview*>(w)->getDocumentTitle();
	}

	//设置铺满
	WEBVIEW_API void webview_setSizeFull(webview_t w) {
		static_cast<webview::webview*>(w)->set_sizeFull();
	}

	//通知父窗口位置已更改
	WEBVIEW_API void webview_notifyParentWindowPositionChanged(webview_t w) {
		static_cast<webview::webview*>(w)->notifyParentWindowPositionChanged();
	}
	
	//执行js代码
	WEBVIEW_API void webview_do_script(webview_t w, const char* js, void(*func)(const int, const wchar_t*)) {
		static_cast<webview::webview*>(w)->doScript(js, func);
	}

	//执行js代码
	WEBVIEW_API void webview_executeScript(webview_t w, const char* js, void(*func)(const int, const wchar_t*)) {
		static_cast<webview::webview*>(w)->doScript(js, func);
	}

	//添加全屏事件
	WEBVIEW_API int webview_addContainsFullScreenElementChanged(webview_t w, void(__stdcall* func)(bool)) {
		return static_cast<webview::webview*>(w)->containsFullScreenElementChanged(func);
	}

	//删除全屏事件
	WEBVIEW_API void webview_removeContainsFullScreenElementChanged(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removeContainsFullScreenElementChanged(index);
	}

	//添加导航开始事件
	WEBVIEW_API int webview_addNavigationStarting(webview_t w, char* (__stdcall* func)(const char*)) {
		return static_cast<webview::webview*>(w)->addNavigationStarting(func);
	}
	//删除导航开始事件
	WEBVIEW_API void webview_removeNavigationStarting(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removeNavigationStarting(index);
	}

	//添加打开新窗口事件
	WEBVIEW_API int webview_addNewWindowRequested(webview_t w, bool(__stdcall* func)(const wchar_t*)) {
		return static_cast<webview::webview*>(w)->addNewWindowRequested(func);
	}

	//删除打开新窗口事件
	WEBVIEW_API void webview_removeNewWindowRequested(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removeNewWindowRequested(index);
	}

	//添加请求权限事件
	WEBVIEW_API int webview_addPermissionRequested(webview_t w, bool(__stdcall* func)(const char*)) {
		return static_cast<webview::webview*>(w)->addPermissionRequested(func);
	}

	//删除请求权限事件
	WEBVIEW_API void webview_removePermissionRequested(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removePermissionRequested(index);
	}

	//返回
	WEBVIEW_API void webview_goBack(webview_t w) {
		static_cast<webview::webview*>(w)->goBack();
	}

	//前进
	WEBVIEW_API void webview_goForward(webview_t w) {
		static_cast<webview::webview*>(w)->goForward();
	}

	//导航到html
	WEBVIEW_API void webview_navigateToString(webview_t w, const char* html) {
		static_cast<webview::webview*>(w)->navigateToString(html);
	}
	//刷新页面
	WEBVIEW_API void webview_reload(webview_t w) {
		static_cast<webview::webview*>(w)->reload();
	}

	//打开默认下载对话框
	WEBVIEW_API void webview_openDefaultDownloadDialog(webview_t w) {
		static_cast<webview::webview*>(w)->openDefaultDownloadDialog();
	}

	//关闭默认下载对话框
	WEBVIEW_API void webview_closeDefaultDownloadDialog(webview_t w) {
		static_cast<webview::webview*>(w)->closeDefaultDownloadDialog();
	}

	//下载管理
	WEBVIEW_API int webview_addDownloadStarting(webview_t w, char* (__stdcall* func)(const char*)) {
		return static_cast<webview::webview*>(w)->addDownloadStarting(func);
	}

	//删除下载管理
	WEBVIEW_API void webview_removeDownloadStarting(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removeDownloadStarting(index);
	}

	//打印
	WEBVIEW_API void webview_print(webview_t w, char* printSettings, void(__stdcall* func)(int, int)) {
		static_cast<webview::webview*>(w)->print(printSettings, func);
	}

	//显示打印机
	WEBVIEW_API int webview_showPrintUI(webview_t w, COREWEBVIEW2_PRINT_DIALOG_KIND printDialogKind) {
		return static_cast<webview::webview*>(w)->showPrintUI(printDialogKind);
	}


	//添加网站图标改变事件
	WEBVIEW_API int webview_addFaviconChanged(webview_t w, void(__stdcall* func)(const wchar_t*)) {
		return static_cast<webview::webview*>(w)->addFaviconChanged(func);
	}

	//删除网站图标改变事件
	WEBVIEW_API void webview_removeFaviconChanged(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removeFaviconChanged(index);
	}

	//运行DevToolsProtocol方法
	WEBVIEW_API void webview_callDevToolsProtocolMethod(webview_t w, char* methodName, char* parametersAsJson, void( *func)(long, const wchar_t*)) {
		return static_cast<webview::webview*>(w)->callDevToolsProtocolMethod(methodName, parametersAsJson, func);
	}

	//判断webview初始化完成
	WEBVIEW_API bool webview_ready(webview_t w) {
		return static_cast<webview::webview*>(w)->isReady;
	}

	//注入在所有顶级文档和子框架页面导航上运行的脚本
	WEBVIEW_API void webview_addScriptToExecuteOnDocumentCreated(webview_t w, const char* js) {
		static_cast<webview::webview*>(w)->init(js);
	}



	//
	WEBVIEW_API int webview_getAreDefaultContextMenusEnabled(webview_t w) {
		return static_cast<webview::webview*>(w)->getAreDefaultContextMenusEnabled();
	}
	WEBVIEW_API void webview_putAreDefaultContextMenusEnabled(webview_t w, int b) {
		static_cast<webview::webview*>(w)->putAreDefaultContextMenusEnabled(b);
	}

	//
	WEBVIEW_API int webview_getAreDefaultScriptDialogsEnabled(webview_t w) {
		return static_cast<webview::webview*>(w)->getAreDefaultScriptDialogsEnabled();
	}
	WEBVIEW_API void webview_putAreDefaultScriptDialogsEnabled(webview_t w, int b) {
		static_cast<webview::webview*>(w)->putAreDefaultScriptDialogsEnabled(b);
	}

	//
	WEBVIEW_API int webview_getAreDevToolsEnabled(webview_t w) {
		return static_cast<webview::webview*>(w)->getAreDevToolsEnabled();
	}
	WEBVIEW_API void webview_putAreDevToolsEnabled(webview_t w, int b) {
		static_cast<webview::webview*>(w)->putAreDevToolsEnabled(b);
	}

	//
	WEBVIEW_API int webview_getAreHostObjectsAllowed(webview_t w) {
		return static_cast<webview::webview*>(w)->getAreHostObjectsAllowed();
	}
	WEBVIEW_API void webview_putAreHostObjectsAllowed(webview_t w, int b) {
		static_cast<webview::webview*>(w)->putAreHostObjectsAllowed(b);
	}

	//
	WEBVIEW_API int webview_getIsBuiltInErrorPageEnabled(webview_t w) {
		return static_cast<webview::webview*>(w)->getIsBuiltInErrorPageEnabled();
	}
	WEBVIEW_API void webview_putIsBuiltInErrorPageEnabled(webview_t w, int b) {
		static_cast<webview::webview*>(w)->putIsBuiltInErrorPageEnabled(b);
	}

	//
	WEBVIEW_API int webview_getIsStatusBarEnabled(webview_t w) {
		return static_cast<webview::webview*>(w)->getIsStatusBarEnabled();
	}
	WEBVIEW_API void webview_putIsStatusBarEnabled(webview_t w, int b) {
		static_cast<webview::webview*>(w)->putIsStatusBarEnabled(b);
	}

	//
	WEBVIEW_API int webview_getIsZoomControlEnabled(webview_t w) {
		return static_cast<webview::webview*>(w)->getIsZoomControlEnabled();
	}
	WEBVIEW_API void webview_putIsZoomControlEnabled(webview_t w, int b) {
		static_cast<webview::webview*>(w)->putIsZoomControlEnabled(b);
	}

	//
	WEBVIEW_API const wchar_t* webview_getUserAgent(webview_t w) {
		return static_cast<webview::webview*>(w)->getUserAgent();
	}
	WEBVIEW_API void webview_putUserAgent(webview_t w, char* s) {
		static_cast<webview::webview*>(w)->putUserAgent(s);
	}

	//
	WEBVIEW_API int webview_getAreBrowserAcceleratorKeysEnabled(webview_t w) {
		return static_cast<webview::webview*>(w)->getAreBrowserAcceleratorKeysEnabled();
	}
	WEBVIEW_API void webview_putAreBrowserAcceleratorKeysEnabled(webview_t w, int b) {
		static_cast<webview::webview*>(w)->putAreBrowserAcceleratorKeysEnabled(b);
	}

	//
	WEBVIEW_API const wchar_t* webview_getDefaultDownloadFolderPath(webview_t w) {
		return static_cast<webview::webview*>(w)->getDefaultDownloadFolderPath();
	}
	WEBVIEW_API void webview_putDefaultDownloadFolderPath(webview_t w, char* s) {
		static_cast<webview::webview*>(w)->putDefaultDownloadFolderPath(s);
	}

	WEBVIEW_API void webview_clearBrowsingData(webview_t w, COREWEBVIEW2_BROWSING_DATA_KINDS dataKinds, void (*func)(int)) {
		static_cast<webview::webview*>(w)->clearBrowsingData(dataKinds,func);
	}

	WEBVIEW_API void webview_clearBrowsingDataAll(webview_t w, void (*func)(int)) {
		static_cast<webview::webview*>(w)->clearBrowsingDataAll(func);
	}

	WEBVIEW_API void webview_clearBrowsingDataInTimeRange(webview_t w, COREWEBVIEW2_BROWSING_DATA_KINDS  dataKinds, double startTime, double endTime, void (*func)(int)) {
		static_cast<webview::webview*>(w)->clearBrowsingDataInTimeRange(dataKinds, startTime, endTime,func);
	}

	//主题颜色
	WEBVIEW_API int webview_getPreferredColorScheme(webview_t w) {
		return static_cast<webview::webview*>(w)->getPreferredColorScheme();
	}
	WEBVIEW_API void webview_putPreferredColorScheme(webview_t w, COREWEBVIEW2_PREFERRED_COLOR_SCHEME b) {
		static_cast<webview::webview*>(w)->putPreferredColorScheme(b);
	}

	//背景色
	WEBVIEW_API int webview_getDefaultBackgroundColor(webview_t w) {
		return static_cast<webview::webview*>(w)->getDefaultBackgroundColor();
	}
	WEBVIEW_API void webview_putDefaultBackgroundColor(webview_t w, int r, int g, int b, int a) {
		static_cast<webview::webview*>(w)->putDefaultBackgroundColor(r,g,b,a);
	}

	//确定 WebView 是否尝试跟踪监视器 DPI 缩放更改
	WEBVIEW_API int webview_getShouldDetectMonitorScaleChanges(webview_t w) {
		return static_cast<webview::webview*>(w)->getShouldDetectMonitorScaleChanges();
	}
	WEBVIEW_API void webview_putShouldDetectMonitorScaleChanges(webview_t w, int b) {
		static_cast<webview::webview*>(w)->putShouldDetectMonitorScaleChanges(b);
	}

	//
	WEBVIEW_API int webview_addIsDocumentPlayingAudioChanged(webview_t w, void(__stdcall* func)(int, int)) {
		return static_cast<webview::webview*>(w)->addIsDocumentPlayingAudioChanged(func);
	}
	//
	WEBVIEW_API void webview_removeIsDocumentPlayingAudioChanged(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removeIsDocumentPlayingAudioChanged(index);
	}

	//
	WEBVIEW_API int webview_addIsMutedChanged(webview_t w, void(__stdcall* func)(int, int)) {
		return static_cast<webview::webview*>(w)->addIsMutedChanged(func);
	}
	//
	WEBVIEW_API void webview_removeIsMutedChanged(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removeIsMutedChanged(index);
	}

	//
	WEBVIEW_API int webview_getIsMuted(webview_t w) {
		return static_cast<webview::webview*>(w)->getIsMuted();
	}
	//
	WEBVIEW_API void webview_putIsMuted(webview_t w, int index) {
		static_cast<webview::webview*>(w)->putIsMuted(index);
	}

	//
	WEBVIEW_API int webview_getIsDocumentPlayingAudio(webview_t w) {
		return static_cast<webview::webview*>(w)->getIsDocumentPlayingAudio();
	}


	//
	WEBVIEW_API void webview_addWebResourceRequestedFilter(webview_t w, char* uri, COREWEBVIEW2_WEB_RESOURCE_CONTEXT resourceContext) {
		static_cast<webview::webview*>(w)->addWebResourceRequestedFilter(uri, resourceContext);
	}

	//
	WEBVIEW_API void webview_removeWebResourceRequestedFilter(webview_t w, char* uri, COREWEBVIEW2_WEB_RESOURCE_CONTEXT resourceContext) {
		static_cast<webview::webview*>(w)->removeWebResourceRequestedFilter(uri, resourceContext);
	}

	//
	WEBVIEW_API int webview_addWebResourceRequested(webview_t w, char* (__stdcall* func)(const char*)) {
		return static_cast<webview::webview*>(w)->addWebResourceRequested(func);
	}

	//
	WEBVIEW_API void webview_removeWebResourceRequested(webview_t w, int index) {
		static_cast<webview::webview*>(w)->removeWebResourceRequested(index);
	}

	//downloadOperation
	WEBVIEW_API int webview_downloadOperation_addBytesReceivedChanged(download_t d, void(__stdcall* func)()) {
		EventRegistrationToken token;
		static_cast<ICoreWebView2DownloadOperation*>(d)->add_BytesReceivedChanged(
			Callback<ICoreWebView2BytesReceivedChangedEventHandler>(
				[func](ICoreWebView2DownloadOperation* download, IUnknown* args)  -> HRESULT {
					func();
					return S_OK;
				})
			.Get(), &token);
		tokenMap.insert({ tokenMapIndex,token });
		return tokenMapIndex++;
	}

	WEBVIEW_API int webview_downloadOperation_addEstimatedEndTimeChanged(download_t d, void(__stdcall* func)()) {
		EventRegistrationToken token;
		static_cast<ICoreWebView2DownloadOperation*>(d)->add_EstimatedEndTimeChanged(
			Callback<ICoreWebView2EstimatedEndTimeChangedEventHandler>(
				[func](ICoreWebView2DownloadOperation* download, IUnknown* args)  -> HRESULT {
					func();
					return S_OK;
				})
			.Get(), &token);
		tokenMap.insert({ tokenMapIndex,token });
		return tokenMapIndex++;
	}

	WEBVIEW_API int webview_downloadOperation_addStateChanged(download_t d, void(__stdcall* func)()) {
		EventRegistrationToken token;
		static_cast<ICoreWebView2DownloadOperation*>(d)->add_StateChanged(
			Callback<ICoreWebView2StateChangedEventHandler>(
				[func](ICoreWebView2DownloadOperation* download, IUnknown* args)  -> HRESULT {
					func();
					return S_OK;
				})
			.Get(), &token);
		tokenMap.insert({ tokenMapIndex,token });
		return tokenMapIndex++;
	}


	WEBVIEW_API INT64 webview_downloadOperation_getBytesReceived(download_t d) {
		INT64 bytesReceived;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_BytesReceived(&bytesReceived);
		return bytesReceived;
	}

	WEBVIEW_API BOOL webview_downloadOperation_getCanResume(download_t d) {
		BOOL canResume;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_CanResume(&canResume);
		return canResume;
	}

	WEBVIEW_API wchar_t* webview_downloadOperation_getContentDisposition(download_t d) {
		LPWSTR contentDisposition;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_ContentDisposition(&contentDisposition);
		return contentDisposition;
	}

	WEBVIEW_API wchar_t* webview_downloadOperation_getEstimatedEndTime(download_t d) {
		LPWSTR estimatedEndTime;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_EstimatedEndTime(&estimatedEndTime);
		return estimatedEndTime;
	}

	WEBVIEW_API int webview_downloadOperation_getInterruptReason(download_t d) {
		COREWEBVIEW2_DOWNLOAD_INTERRUPT_REASON interruptReason;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_InterruptReason(&interruptReason);
		return interruptReason;
	}

	WEBVIEW_API wchar_t* webview_downloadOperation_getMimeType(download_t d) {
		LPWSTR mimeType;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_MimeType(&mimeType);
		return mimeType;
	}

	WEBVIEW_API wchar_t* webview_downloadOperation_getResultFilePath(download_t d) {
		LPWSTR resultFilePath;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_ResultFilePath(&resultFilePath);
		return resultFilePath;
	}
	
	WEBVIEW_API int webview_downloadOperation_getState(download_t d) {
		COREWEBVIEW2_DOWNLOAD_STATE state;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_State(&state);
		return state;
	}

	WEBVIEW_API INT64 webview_downloadOperation_getTotalBytesToReceive(download_t d) {
		INT64 totalBytesToReceive;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_TotalBytesToReceive(&totalBytesToReceive);
		return totalBytesToReceive;
	}

	WEBVIEW_API wchar_t* webview_downloadOperation_getUri(download_t d) {
		LPWSTR uri;
		static_cast<ICoreWebView2DownloadOperation*>(d)->get_Uri(&uri);
		return uri;
	}

	WEBVIEW_API void webview_downloadOperation_cancel(download_t d) {
		static_cast<ICoreWebView2DownloadOperation*>(d)->Cancel();
	}

	WEBVIEW_API void webview_downloadOperation_pause(download_t d) {
		static_cast<ICoreWebView2DownloadOperation*>(d)->Pause();
	}

	WEBVIEW_API void webview_downloadOperation_resume(download_t d) {
		static_cast<ICoreWebView2DownloadOperation*>(d)->Resume();
	}

	WEBVIEW_API void webview_downloadOperation_removeBytesReceivedChanged(download_t d,int index) {
		static_cast<ICoreWebView2DownloadOperation*>(d)->remove_BytesReceivedChanged(tokenMap[index]);
	}

	WEBVIEW_API void webview_downloadOperation_removeEstimatedEndTimeChanged(download_t d, int index) {
		static_cast<ICoreWebView2DownloadOperation*>(d)->remove_EstimatedEndTimeChanged(tokenMap[index]);
	}

	WEBVIEW_API void webview_downloadOperation_removeStateChanged(download_t d, int index) {
		static_cast<ICoreWebView2DownloadOperation*>(d)->remove_StateChanged(tokenMap[index]);
	}




	//
	WEBVIEW_API int webview_addScriptDialogOpening(webview_t w, char* (__stdcall* func)(const char*)) {
		return static_cast<webview::webview*>(w)->addScriptDialogOpening(func);
	}

	//
	WEBVIEW_API void webview_scriptDialogOpeningEventArgs_accept(com_t c) {
		static_cast<ICoreWebView2ScriptDialogOpeningEventArgs*>(c)->Accept();
	}

	//
	WEBVIEW_API void webview_scriptDialogOpeningEventArgs_putResultText(com_t c, wchar_t* t) {
		static_cast<ICoreWebView2ScriptDialogOpeningEventArgs*>(c)->put_ResultText(t);
	}

	//
	WEBVIEW_API void webview_deferral_complete(deferral_t d) {
		static_cast<ICoreWebView2Deferral*>(d)->Complete();
	}

#ifdef __cplusplus
}
#endif

