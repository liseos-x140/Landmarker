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
        
        // post
        recoginitionLandmarkImage(image: originalImage!)
        
        titleLabel.text = "Landmarkの名前"
        documentLabel.text = "Landmarkの説明"
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBOutlet weak var targetImage: UIImageView!
    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var documentLabel: UILabel!
    
    var originalImage : UIImage?
    
    struct response_docomoAPI: Codable {
        let candidates: (candidate)
        let jobId: String
    }
    
    struct candidate: Codable{
        let score: String
        let tag: String
    }
    
    func recoginitionLandmarkImage(image: UIImage){
        let headers: HTTPHeaders = ["Content-Type": "multipart/form-data"]
        //let parameters: Parameters = ["modelName":"landmark"]
        
        //var name_landmark: String?
        
        Alamofire.upload(
            multipartFormData :{ (MultipartFormData) in
                // image
                MultipartFormData.append(UIImageJPEGRepresentation(image, 1)!, withName: "image", fileName: "sample.jpeg", mimeType: "image/jpeg")
                
                // param
                //MultipartFormData.append(data: "landmark", withName: "modelName")
                MultipartFormData.append("landmark".data(using: .utf8)!, withName: "modelName")
                
                /**
                for (key,value) in parameters{
                    MultipartFormData.append(data: (value as AnyObject).dataUsingEncoding(String.Encoding.utf8.rawValue)!, name: key)
                } **/
                //dump(MultipartFormData)
        },
            to: "https://api.apigw.smt.docomo.ne.jp/imageRecognition/v1/concept/classify/?APIKEY=6d667135466d7a414c2e6c477458724d5353764d61315170584647726d6647757639416854427639527a42",
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
                        
                        //name_landmark = json["candidates"][0]["tag"].stringValue
                    }
                case .failure(let encodingError):
                    // 失敗
                    print("error")
                    print(encodingError)
                }
            }
        )
        
        //return name_landmark!
        
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


