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

class explainingViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
        
        // 画面遷移時に画像を表示
        targetImage.image = originalImage
        
        // post
        //
        
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
    
    
    
    
    
    func recoginitionLandmarkImage(image: UIImage) -> String{
        let headers: HTTPHeaders = ["Content-Type": "multipart/form-data"]
        let parameters: Parameters = ["APIKEY": "6d667135466d7a414c2e6c477458724d5353764d61315170584647726d6647757639416854427639527a42", "modelName":"landmark"]
        
        Alamofire.upload(
            "https://api.apigw.smt.docomo.ne.jp/imageRecognition/v1/concept/classify",
            method: .post,
            headers: headers,
            multipartFormData: { multipartFormData in
                multipartFormData.append(UIImageJPEGRepresentation(image), withName: "image", mimeType: "image/jpeg")
                
                for (key,value) in parameters{
                    multipartFormData.append(data: value.dataUsingEncoding(NSUTF8StringEncoding)!, name: key)
                }
            },
            encodingCompletion: { encodingResult in
                switch encodingResult {
                case .success(let upload, _, _):
                    upload.responseJSON { response in
                        // 成功
                        let responseData = response
                        print(responseData ?? "成功")
                    }
                case .failure(let encodingError):
                    // 失敗
                    print(encodingError)
                }
            }
        )
        
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


