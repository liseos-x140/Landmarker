//
//  explainingViewController.swift
//  Landmarker
//
//  Created by Masashi Uemura on 2018/04/19.
//  Copyright © 2018年 Masashi Uemura. All rights reserved.
//

import UIKit
import ImageRecognition
import Alamofire
import SwiftyJSON

class explainingViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        // 画面遷移時に画像を表示
        targetImage.image = originalImage
        
        // 初期テキスト
        titleLabel.text = "Landmark名"
        documentView.text = "Landmarkの説明"
        
        // 画像からランドマークを特定 (docomoAPI)
        let lm_name = recoginitionLandmarkImage(image: originalImage!)
        
        // ランドマーク名から説明を取得 (公共クラウドAPI)
        //print(lm_name)
        //getLandmarkDescription(landmarkN: lm_name)
        
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBOutlet weak var targetImage: UIImageView!
    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var documentView: UITextView!
    
    var originalImage : UIImage?
    
    struct response_docomoAPI: Codable {
        let candidates: (candidate)
        let jobId: String
    }
    
    struct candidate: Codable{
        let score: String
        let tag: String
    }
    
    func getLandmarkWikiDescription(landmarkN: String){
        // set url & params
        let url: String = "http://ja.wikipedia.org/w/api.php"
        let parameters: Parameters = ["format":"json",
                                      "action":"query",
                                      "prop":"revisions",
                                      "rvprop":"content",
                                      "titles":landmarkN]
        
        Alamofire.request(url, method: .get, parameters:parameters).responseJSON{
            response in
            let json = JSON(response.result.value as Any)
            print(json)
            print(json["tourspots"][0]["descs"][0]["body"].stringValue)
            self.documentView.text = json["tourspots"][0]["descs"][0]["body"].stringValue
        }
        
    }
    
    func getLandmarkDescription(landmarkN: String){
        let genres : String = ["郷土景観", "展望施設", "庭園", "城郭", "旧街道", "史跡", "歴史的建造物", "近代的建造物", "産業観光施設", "神社・仏閣等"].map{
            $0.addingPercentEncoding(withAllowedCharacters: .urlQueryAllowed)!
            }.joined(separator: ";")
        print(genres)
        
        print(landmarkN)
        var name = landmarkN.pregReplace(pattern: ".+/", with: "")
        print(name)
        name = name.pregReplace(pattern: "_", with: " ")
        print(name)
        
        let url:String = "https://www.chiikinogennki.soumu.go.jp/k-cloud-api/v001/kanko/\(genres)/json"
        let parameters: Parameters = ["limit":"5",
                                      "name":name]
        var searchFlag: Bool
        
        print(url)
        
        Alamofire.request(url, method: .get, parameters:parameters).responseJSON{
            response in
                let json = JSON(response.result.value as Any)
                print(json)
                print(json["tourspots"][0]["descs"][0]["body"].stringValue)
                self.documentView.text = json["tourspots"][0]["descs"][0]["body"].stringValue
        }
        
    }
    
    func recoginitionLandmarkImage(image: UIImage) -> String{
        let headers: HTTPHeaders = ["Content-Type": "multipart/form-data"]
        //let parameters: Parameters = ["modelName":"landmark"]
        
        var name_landmark: String? = "Landmark名"
        
        Alamofire.upload(
            multipartFormData :{ (MultipartFormData) in
                // image
                MultipartFormData.append(UIImageJPEGRepresentation(image, 1)!, withName: "image", fileName: "sample.jpeg", mimeType: "image/jpeg")
                
                // param
                MultipartFormData.append("landmark".data(using: .utf8)!, withName: "modelName")
                
        },
            to: "https://api.apigw.smt.docomo.ne.jp/imageRecognition/v1/concept/classify/?APIKEY=xxxx",
            //method: .POST,
            headers: headers,
            encodingCompletion: { encodingResult in
                switch encodingResult {
                case .success(let upload, _, _):
                    upload.responseJSON { response in
                        // 成功
                        let responseData = response
                        print("!success!")
                        print(responseData)
                        
                        print("----- json parse -----")
                        let json:JSON = JSON(responseData.result.value ?? kill)
                        print(json["candidates"][0]["tag"].stringValue)
                        print(type(of: json["candidates"][0]["tag"].stringValue))
                        
                        self.titleLabel.text = json["candidates"][0]["tag"].stringValue
                        
                        name_landmark = json["candidates"][0]["tag"].stringValue
                        // get 説明
                        self.getLandmarkDescription(landmarkN: name_landmark!)
                    }
                case .failure(let encodingError):
                    // 失敗
                    print("error")
                    print(encodingError)
                }
            }
        )
        
        return name_landmark!
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */
    
    

}


