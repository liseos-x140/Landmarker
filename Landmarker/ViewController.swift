//
//  ViewController.swift
//  Landmarker
//
//  Created by Masashi Uemura on 2018/04/18.
//  Copyright © 2018年 Masashi Uemura. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class ViewController: UIViewController, UINavigationControllerDelegate , UIImagePickerControllerDelegate, UITextFieldDelegate, CLLocationManagerDelegate, UIGestureRecognizerDelegate {
    
    @IBOutlet weak var inputText: UITextField!
    @IBOutlet weak var dispMap: MKMapView!
    @IBOutlet weak var coordinateLabel: UILabel!
    var locationManager : CLLocationManager!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        // MapViewを生成
        self.dispMap.showsUserLocation = true
        
        locationManager = CLLocationManager.init()
        locationManager.allowsBackgroundLocationUpdates = true // バックグランドモードで使用する場合trueにする必要がある
        locationManager.desiredAccuracy = kCLLocationAccuracyBest // 位置情報取得の精度
        locationManager.distanceFilter = 10 // 位置情報取得する間隔、1m単位とする
        locationManager.delegate = self as? CLLocationManagerDelegate
        
        // Text Field Delegate設定
        inputText.delegate = self
        
        // LongTapの設定
        let longTapGesture = UILongPressGestureRecognizer(target: self, action: #selector(longTap(_:)))
        longTapGesture.delegate = self
        dispMap.addGestureRecognizer(longTapGesture)
    }
    
    /*     位置情報     */
    // 位置情報が取得されると呼ばれる
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        // 最新の位置情報を取得 locationsに配列で入っている位置情報の最後が最新となる
        let location : CLLocation = locations.last!
        
        // 座標表示
        print("緯度:\(location.coordinate.latitude) 経度:\(location.coordinate.longitude) 取得時刻:\(location.timestamp.description)")
        coordinateLabel.text = String(format: "緯度: %.3f 経度: %.3f",location.coordinate.latitude, location.coordinate.longitude)
        print(String(describing: type(of: location.coordinate.latitude)))
        
        // test
        // searchLandmarkByCoordinate(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude)
        
        // アプリ起動時の表示領域設定
        let mySpan = MKCoordinateSpan(latitudeDelta: 0.05, longitudeDelta: 0.05)
        let myRegion = MKCoordinateRegionMake(location.coordinate, mySpan)
        self.dispMap.region = myRegion
    }
    
    // 位置情報の取得に失敗すると呼ばれる
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        print("位置情報を取得できません")
    }
    
    // 位置情報の認証関連 + startUpdatingLocation
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if (status == .restricted) {
            print("GPS機能制限");
        }
        else if (status == .denied) {
            print("GPSの使用を許可してください");
        }
        else if (status == .authorizedWhenInUse) {
            print("このアプリ使用中のみGPSの使用を許可");
            locationManager.startUpdatingLocation();
        }
        else if (status == .authorizedAlways) {
            print("常にGPSの使用を許可");
            locationManager.startUpdatingLocation();
        }
    }
 

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        // キーボードを閉じる(1)
        textField.resignFirstResponder()
        
        // 入力された文字を取り出す(2)
        if let searchKey = textField.text {
            
            // 入力された文字をデバックエリアに表示(3)
            print(searchKey)
            
            // CLGeocoderインスタンスを取得(5)
            let geocoder = CLGeocoder()
            
            // 入力された文字から位置情報を取得(6)
            geocoder.geocodeAddressString(searchKey, completionHandler: { (placemarks, error) in
                
                // 位置情報が存在する場合はunwarpPlacemarksに取り出す(7)
                if let unwarpPlacemarks = placemarks {
                    
                    // 1件目の情報を取り出す(8)
                    if let firstPlacemark = unwarpPlacemarks.first {
                        
                        // 位置情報を取り出す(9)
                        if let location = firstPlacemark.location {
                            
                            // 位置情報から緯度経度をtargetCoordinateに取り出す(10)
                            let targetCoordinate = location.coordinate
                            
                            // 緯度経度をデバックエリアに表示(11)
                            print(targetCoordinate)
                            
                            // MKPointAnnotationインスタンスを取得し、ピンを生成(12)
                            let pin = MKPointAnnotation()
                            
                            // ピンの置く場所に経度緯度を設定(13)
                            pin.coordinate = targetCoordinate
                            
                            // ピンのタイトルを設定(14)
                            pin.title = searchKey
                            
                            // ピンを地図に置く(15)
                            self.dispMap.addAnnotation(pin)
                            
                            // 緯度経度を中心にして半径500mの範囲を表示(16)
                            self.dispMap.region = MKCoordinateRegionMakeWithDistance(targetCoordinate, 500.0, 500.0)
                            
                            // API test
                            self.searchLandmarkByCoordinate(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude)
                        }
                    }
                }
            })
        }
        
        // デフォルト動作を行うのでtrueを返す(4)
        return true
    }
    
    @IBAction func changeMapButtonAction(_ sender: Any) {
        // mapTypeプロパティー値をトグル
        //  標準(.standard) → 航空写真(.satellite) → 航空写真+標準(.hybrid)
        //  → 3D Flyover(.satelliteFlyover) → 3D Flyover+標準(.hybridFlyover)
        if dispMap.mapType == .standard {
            dispMap.mapType = .satellite
        } else if dispMap.mapType == .satellite {
            dispMap.mapType = .hybrid
        } else if dispMap.mapType == .hybrid {
            dispMap.mapType = .satelliteFlyover
        } else if dispMap.mapType == .satelliteFlyover {
            dispMap.mapType = .hybridFlyover
        } else {
            dispMap.mapType = .standard
        }
    }
    
    @IBAction func transitionPhotoModeController(_ sender: Any) {
        // カメラ or フォトライブラリーかの選択
        let alertController = UIAlertController(title: "確認", message: "選択してください", preferredStyle: .actionSheet)
        
        // カメラが使用可能かのチェック
        if UIImagePickerController.isSourceTypeAvailable(.camera){
            // カメラを起動するための選択肢を定義
            let cameraAction = UIAlertAction(title: "カメラ", style: .default, handler: { (action: UIAlertAction) in
                // カメラ起動
                let imagePickerController : UIImagePickerController = UIImagePickerController()
                imagePickerController.sourceType = .camera
                imagePickerController.delegate = self
                self.present(imagePickerController, animated: true, completion: nil)
            })
            alertController.addAction(cameraAction)
        }
        
        if UIImagePickerController.isSourceTypeAvailable(.photoLibrary){
            // フォトライブラリーを起動するための選択肢を定義
            let photoLibraryAction = UIAlertAction(title: "フォトライブラリー", style: .default, handler: { (action: UIAlertAction) in
                // フォトライブラリーを起動
                let imagePickerController : UIImagePickerController = UIImagePickerController()
                imagePickerController.sourceType = .photoLibrary
                imagePickerController.delegate = self
                self.present(imagePickerController, animated: true, completion: nil)
            })
            alertController.addAction(photoLibraryAction)
        }
        
        // キャンセルの選択肢を定義
        let cancelAction = UIAlertAction(title: "キャンセル", style: .cancel, handler: nil)
        alertController.addAction(cancelAction)
        
        // iPadで落ちてしまう対策
        alertController.popoverPresentationController?.sourceView = view
        
        // 選択肢を画面に定義
        present(alertController, animated: true, completion: nil)
    }
    

    
    // (1)撮影が終わったときに呼ばれるdelegateメソッド
    @objc func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [String : Any]) {
        // (2)撮影した写真を、配置したcaptureImageに渡す
        captureImage = info[UIImagePickerControllerOriginalImage] as? UIImage
        // (3)モーダルビューを閉じる
        dismiss(animated: true, completion: {
            // (4)解析画面に遷移
            self.performSegue(withIdentifier: "goExplaining", sender: nil)
        })
    }
    
    // 次の画面遷移するときに渡す画像を格納する場所
    var captureImage : UIImage?
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // 次の画面のインスタンスを格納
        if let nextViewController = segue.destination as? explainingViewController {
            //次の画面のインスタンスに取得した画像を渡す
            nextViewController.originalImage = captureImage
        }
    }
    
    /*  gesture  */
    @objc func longTap(_ sender: UIGestureRecognizer){
        print("Long tap")
        if sender.state == .ended {
            print("UIGestureRecognizerStateEnded")
            //Do Whatever You want on End of Gesture
        }
        else if sender.state == .began {
            print("UIGestureRecognizerStateBegan.")
            //Do Whatever You want on Began of Gesture
            
            let tappedLocation = sender.location(in: dispMap)
            let tappedPoint = dispMap.convert(tappedLocation, toCoordinateFrom: dispMap)
            
            // pin
            //ピンの生成
            let pin = MKPointAnnotation()
            //ピンを置く場所を指定
            pin.coordinate = tappedPoint
            //ピンのタイトルを設定
            pin.title = "タイトル"
            //ピンのサブタイトルの設定
            pin.subtitle = "サブタイトル"
            //ピンをMapViewの上に置く
            self.dispMap.addAnnotation(pin)
        }
    }
    
    
    /*  API関連の処理 */
    // JSON structure
    struct ItemJson: Codable{
        let name: String?
        let descs: String?
        let uri : String?
        let latitude : Double?
        let longtitude : Double?
    }
    
    // ジャンルリスト
    let genres : String = ["郷土景観", "展望施設", "庭園", "城郭", "旧街道", "史跡", "歴史的建造物", "近代的建造物", "産業観光施設", "神社・仏閣等"].map{
         $0.addingPercentEncoding(withAllowedCharacters: .urlQueryAllowed)!
    }.joined(separator: ",")
    
    func searchLandmarkByCoordinate(latitude : Double, longitude: Double){
        // req_url = "https://<ホスト名>/k-cloud-api/<バージョン>/kanko/<ジャンル>/<出 力データ形式>?<パラメータ群>"
        guard let req_url = URL(string: "https://www.chiikinogennki.soumu.go.jp/k-cloud-api/v001/kanko/\(genres)/json?limit=20&coordinates=\(latitude),\(longitude)") else {
            return
        }
        // for debug
        print(req_url)
        
    }
    
}

