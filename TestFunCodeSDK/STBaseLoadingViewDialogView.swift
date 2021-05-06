//
//  STBaseLoadingViewDialogView.swift
//  InvoiceMonster
//
//  Created by Phoebe.Lin on 2021/4/29.
//  Copyright © 2021 Friendo. All rights reserved.
//

import Foundation
import SnapKit
import Lottie

class STBaseLoadingViewDialogView: UIView{
    
    lazy var maskerView: UIView = {
        let maskerView = UIView()
        maskerView.backgroundColor = UIColor.white
        maskerView.layer.cornerRadius = 10
        maskerView.layer.masksToBounds = true
        return maskerView
    }()
    
    lazy var titleLabel: UILabel = {
        let titleLabel = UILabel()
//        titleLabel.text = "打卡驗證中..."
        titleLabel.textColor = .darkGray
        titleLabel.textAlignment = .center
        titleLabel.font = UIFont(name:"PingFangTC-Semibold", size: 22.0)
        return titleLabel
    }()

    lazy var animationView: UIView = {
        let animationView = UIView()
        animationView.backgroundColor = UIColor.clear
        return animationView
    }()

    override init(frame: CGRect) {
        super.init(frame: frame)
        initSubviews()
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
    
    private func initSubviews() {
        
        self.frame = UIScreen.main.bounds
        self.backgroundColor = UIColor.init(red: 0, green: 0, blue: 0, alpha: 0.5)
        
        self.addSubview(maskerView)
        self.addSubview(titleLabel)
        self.addSubview(animationView)
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        
        let space :CGFloat = 28.0;
        let bounds = UIScreen.main.bounds
        let width = bounds.size.width
        let tempW = width - (space * 2);
        let tempH :CGFloat = 320.0;
        
        maskerView.snp.makeConstraints { (make) -> Void in
            make.center.equalTo(self)
            make.width.equalTo(tempW)
            make.height.equalTo(tempH)
        }

        titleLabel.snp.makeConstraints { (make) -> Void in
            make.top.equalTo(maskerView.snp.top).offset(28)
            make.left.equalTo(maskerView.snp.left).offset(50)
            make.right.equalTo(maskerView.snp.right).offset(-50)
            make.height.equalTo(32)
        }
        
        animationView.snp.makeConstraints { (make) -> Void in
            make.bottom.equalTo(maskerView.snp.bottom).offset(-25)
            make.centerX.equalTo(self)
            make.width.equalTo(220)
            make.height.equalTo(220)
        }
    }
    
    @objc open func showDialog(title :String, lottieName :String) {
        
        titleLabel.text = title
        
        let lottieView = LOTAnimationView(name: lottieName)
        animationView.addSubview(lottieView)

        lottieView.contentMode = .scaleAspectFill
        lottieView.loopAnimation = true;
        lottieView.play{ (finished) in
            lottieView.snp.makeConstraints { (make) -> Void in
                make.edges.equalTo(self.animationView)
            }
        }
    }
}
