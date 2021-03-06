/****************************************************************************
 *
 * CRI Middleware SDK
 *
 * Copyright (c) 2010-2015 CRI Middleware Co., Ltd.
 *
 * Library  : CRI Atom
 * Module   : Library User's Header for PC
 * File     : cri_le_atom_pc.h
 *
 ****************************************************************************/
/*!
 *	\file		cri_le_atom_pc.h
 */

/* 多重定義防止					*/
/* Prevention of redefinition	*/
#ifndef	CRI_INCL_CRI_ATOM_PC_H
#define	CRI_INCL_CRI_ATOM_PC_H

/***************************************************************************
 *      インクルードファイル
 *      Include files
 ***************************************************************************/
#include <windows.h>
#include <cri_le_xpt.h>
#include <cri_le_error.h>
#include <cri_le_atom.h>
#include <cri_le_atom_ex.h>
#include <cri_le_atom_asr.h>

/***************************************************************************
 *      定数マクロ
 *      Macro Constants
 ***************************************************************************/

/***************************************************************************
 *      処理マクロ
 *      Macro Functions
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用コンフィグ構造体にデフォルト値をセット
 * \ingroup ATOMLIB_PC
 * \param[out]	p_config	初期化用コンフィグ構造体へのポインタ
 * \par 説明:
 * ::criAtomEx_Initialize_PC 関数に設定するコンフィグ構造体
 * （ ::CriAtomExConfig_PC ）に、デフォルトの値をセットします。<br>
 * \sa CriAtomExConfig_PC
 */
#define criAtomEx_SetDefaultConfig_PC(p_config)				\
{															\
	criAtomEx_SetDefaultConfig(&(p_config)->atom_ex);		\
	criAtomExAsr_SetDefaultConfig(&(p_config)->asr);		\
	criAtomExHcaMx_SetDefaultConfig(&(p_config)->hca_mx);	\
}

/***************************************************************************
 *      データ型宣言
 *      Data Type Declarations
 ***************************************************************************/
/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief Atomライブラリ初期化用コンフィグ構造体
 * \ingroup ATOMLIB_PC
 * CRI Atomライブラリの動作仕様を指定するための構造体です。<br>
 * ::criAtomEx_Initialize_PC 関数の引数に指定します。<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_SetDefaultConfig_PC
 */
typedef struct CriAtomExConfigTag_PC{
	CriAtomExConfig			atom_ex;	/*JP< AtomEx初期化用コンフィグ構造体	*/
	CriAtomExAsrConfig		asr;		/*JP< ASR初期化用コンフィグ			*/
	CriAtomExHcaMxConfig	hca_mx;		/*JP< HCA-MX初期化用コンフィグ構造体	*/
} CriAtomExConfig_PC;

/***************************************************************************
 *      変数宣言
 *      Prototype Variables
 ***************************************************************************/

/***************************************************************************
 *      関数宣言
 *      Prototype Functions
 ***************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*==========================================================================
 *      CRI Atom API
 *=========================================================================*/



/*JP
 * \brief サーバ処理スレッドのプライオリティ変更
 * \ingroup ATOMLIB_PC
 * \param[in]	prio	スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを変更します。<br>
 * デフォルト状態（本関数を実行しない場合）では、サーバ処理スレッドのプライオリティは
 * THREAD_PRIORITY_HIGHEST に設定されます。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数は何も処理を行いません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行しても、効果はありません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * サーバ処理スレッドは、CRI File Systemライブラリでも利用されています。<br>
 * すでにCRI File SystemライブラリのAPIでサーバ処理スレッドの設定を変更している場合
 * 本関数により設定が上書きされますのでご注意ください。<br>
 * \sa criAtom_Initialize_PC, criAtom_GetThreadPriority_PC
 */
void CRIAPI criAtom_SetThreadPriority_PC(int prio);

/*JP
 * \brief サーバ処理スレッドのプライオリティ取得
 * \ingroup ATOMLIB_PC
 * \return	int		スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを取得します。<br>
 * 取得に成功すると、本関数はサーバ処理を行うスレッドのプライオリティを返します。<br>
 * 取得に失敗した場合、本関数は THREAD_PRIORITY_ERROR_RETURN を返します。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * \sa criAtom_Initialize_PC, criAtom_SetThreadPriority_PC
 */
int CRIAPI criAtom_GetThreadPriority_PC(void);

/*JP
 * \brief サーバ処理スレッドのアフィニティマスク変更
 * \ingroup ATOMLIB_PC
 * \param[in]	mask	スレッドアフィニティマスク
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのアフィニティマスクを変更します。<br>
 * デフォルト状態（本関数を実行しない場合）では、サーバ処理が動作するプロセッサは
 * 一切制限されません。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数は何も処理を行いません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行しても、効果はありません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * サーバ処理スレッドは、CRI File Systemライブラリでも利用されています。<br>
 * すでにCRI File SystemライブラリのAPIでサーバ処理スレッドの設定を変更している場合
 * 本関数により設定が上書きされますのでご注意ください。<br>
 * \sa criAtom_Initialize_PC, criAtom_GetThreadAffinityMask_PC
 */
void CRIAPI criAtom_SetThreadAffinityMask_PC(DWORD_PTR mask);

/*JP
 * \brief サーバ処理スレッドのアフィニティマスクの取得
 * \ingroup ATOMLIB_PC
 * \return	DWORD_PTR	スレッドアフィニティマスク
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのアフィニティマスクを取得します。<br>
 * 取得に成功すると、本関数はサーバ処理を行うスレッドのアフィニティマスクを返します。<br>
 * 取得に失敗した場合、本関数は 0 を返します。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * \sa criAtom_Initialize_PC, criAtom_SetThreadAffinityMask_PC
 */
DWORD_PTR CRIAPI criAtom_GetThreadAffinityMask_PC(void);

/*==========================================================================
 *      CRI AtomEx API
 *=========================================================================*/
/*JP
 * \brief ライブラリ初期化用ワーク領域サイズの計算
 * \ingroup ATOMLIB_PC
 * \param[in]	config		初期化用コンフィグ構造体
 * \return		CriSint32	ワーク領域サイズ
 * \par 説明:
 * ライブラリを使用するために必要な、ワーク領域のサイズを取得します。<br>
 * \par 備考:
 * ライブラリが必要とするワーク領域のサイズは、ライブラリ初期化用コンフィグ
 * 構造体（ ::CriAtomExConfig_PC ）の内容によって変化します。<br>
 * <br>
 * 引数 config の情報は、関数内でのみ参照されます。<br>
 * 関数を抜けた後は参照されませんので、関数実行後に config の領域を解放しても
 * 問題ありません。
 * \sa CriAtomExConfig_PC, criAtomEx_Initialize_PC
 */
CriSint32 CRIAPI criAtomEx_CalculateWorkSize_PC(const CriAtomExConfig_PC *config);

/*JP
 * \brief ライブラリの初期化
 * \ingroup ATOMLIB_PC
 * \param[in]	config		初期化用コンフィグ構造体
 * \param[in]	work		ワーク領域
 * \param[in]	work_size	ワーク領域サイズ
 * \par 説明:
 * ライブラリを初期化します。<br>
 * ライブラリの機能を利用するには、必ずこの関数を実行する必要があります。<br>
 * （ライブラリの機能は、本関数を実行後、 ::criAtomEx_Finalize_PC 関数を実行するまでの間、
 * 利用可能です。）<br>
 * <br>
 * ライブラリを初期化する際には、ライブラリが内部で利用するためのメモリ領域（ワーク領域）
 * を確保する必要があります。<br>
 * ライブラリが必要とするワーク領域のサイズは、初期化用コンフィグ構造体の内容に応じて
 * 変化します。<br>
 * ワーク領域サイズの計算には、 ::criAtomEx_CalculateWorkSize_PC 
 * 関数を使用してください。<br>
 * \par 備考:
 * ::criAtomEx_SetUserAllocator マクロを使用してアロケータを登録済みの場合、
 * 本関数にワーク領域を指定する必要はありません。<br>
 * （ work に NULL 、 work_size に 0 を指定することで、登録済みのアロケータ
 * から必要なワーク領域サイズ分のメモリが動的に確保されます。）
 * <br>
 * 引数 config の情報は、関数内でのみ参照されます。<br>
 * 関数を抜けた後は参照されませんので、関数実行後に config の領域を解放しても
 * 問題ありません。
 * \attention
 * 本関数は内部的に以下の関数を実行します。<br>
 * 	- ::criAtomEx_Initialize
 * 	- ::criAtomExAsr_Initialize
 * 	- ::criAtomExHcaMx_Initialize
 * 	.
 * 本関数を実行する場合、上記関数を実行しないでください。<br>
 * <br>
 * 本関数を実行後、必ず対になる ::criAtomEx_Finalize_PC 関数を実行してください。<br>
 * また、 ::criAtomEx_Finalize_PC 関数を実行するまでは、本関数を再度実行しないでください。<br>
 * \sa CriAtomExConfig_PC, criAtomEx_Finalize_PC,
 * criAtomEx_SetUserAllocator, criAtomEx_CalculateWorkSize_PC
 */
void CRIAPI criAtomEx_Initialize_PC(
	const CriAtomExConfig_PC *config, void *work, CriSint32 work_size);

/*JP
 * \brief ライブラリの終了
 * \ingroup ATOMLIB_PC
 * \par 説明:
 * ライブラリを終了します。<br>
 * \attention
 * 本関数は内部的に以下の関数を実行します。<br>
 * 	- ::criAtomEx_Finalize
 * 	- ::criAtomExAsr_Finalize
 * 	- ::criAtomExHcaMx_Finalize
 * 	.
 * 本関数を実行する場合、上記関数を実行しないでください。<br>
 * <br>
 * ::criAtomEx_Initialize_PC 関数実行前に本関数を実行することはできません。<br>
 * \sa criAtomEx_Initialize_PC
 */
void CRIAPI criAtomEx_Finalize_PC(void);

/*JP
 * \brief サーバ処理スレッドのプライオリティ変更
 * \ingroup ATOMLIB_PC
 * \param[in]	prio	スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを変更します。<br>
 * デフォルト状態（本関数を実行しない場合）では、サーバ処理スレッドのプライオリティは
 * THREAD_PRIORITY_HIGHEST に設定されます。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数は何も処理を行いません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行しても、効果はありません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * サーバ処理スレッドは、CRI File Systemライブラリでも利用されています。<br>
 * すでにCRI File SystemライブラリのAPIでサーバ処理スレッドの設定を変更している場合
 * 本関数により設定が上書きされますのでご注意ください。<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_GetThreadPriority_PC
 */
#define criAtomEx_SetThreadPriority_PC(prio)	\
	criAtom_SetThreadPriority_PC(prio)

/*JP
 * \brief サーバ処理スレッドのプライオリティ取得
 * \ingroup ATOMLIB_PC
 * \return	int		スレッドプライオリティ
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのプライオリティを取得します。<br>
 * 取得に成功すると、本関数はサーバ処理を行うスレッドのプライオリティを返します。<br>
 * 取得に失敗した場合、本関数は THREAD_PRIORITY_ERROR_RETURN を返します。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_SetThreadPriority_PC
 */
#define criAtomEx_GetThreadPriority_PC()	\
	criAtom_GetThreadPriority_PC()

/*JP
 * \brief サーバ処理スレッドのアフィニティマスク変更
 * \ingroup ATOMLIB_PC
 * \param[in]	mask	スレッドアフィニティマスク
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのアフィニティマスクを変更します。<br>
 * デフォルト状態（本関数を実行しない場合）では、サーバ処理が動作するプロセッサは
 * 一切制限されません。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数は何も処理を行いません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行しても、効果はありません。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * サーバ処理スレッドは、CRI File Systemライブラリでも利用されています。<br>
 * すでにCRI File SystemライブラリのAPIでサーバ処理スレッドの設定を変更している場合
 * 本関数により設定が上書きされますのでご注意ください。<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_GetThreadAffinityMask_PC
 */
#define criAtomEx_SetThreadAffinityMask_PC(mask)	\
	criAtom_SetThreadAffinityMask_PC(mask)

/*JP
 * \brief サーバ処理スレッドのアフィニティマスクの取得
 * \ingroup ATOMLIB_PC
 * \return	DWORD_PTR	スレッドアフィニティマスク
 * \par 説明:
 * サーバ処理（ライブラリの内部処理）を行うスレッドのアフィニティマスクを取得します。<br>
 * 取得に成功すると、本関数はサーバ処理を行うスレッドのアフィニティマスクを返します。<br>
 * 取得に失敗した場合、本関数は 0 を返します。<br>
 * \attention:
 * 本関数は、ライブラリ初期化時にスレッドモデルをマルチスレッドモデル
 * （ ::CRIATOM_THREAD_MODEL_MULTI ）に設定した場合にのみ効果を発揮します。<br>
 * 他のスレッドモデルを選択した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * <br>
 * 本関数は初期化後〜終了処理前の間に実行する必要があります。<br>
 * 初期化前や終了処理後に本関数を実行した場合、本関数はエラー値を返します。<br>
 * （エラーコールバックが発生します。）<br>
 * \sa criAtomEx_Initialize_PC, criAtomEx_SetThreadAffinityMask_PC
 */
#define criAtomEx_GetThreadAffinityMask_PC()	\
	criAtom_GetThreadAffinityMask_PC()

#ifdef __cplusplus
}
#endif

#endif	/* CRI_INCL_CRI_ATOM_PC_H */

/* --- end of file --- */
