# -*- coding: utf-8 -*-


from cocoachina.items import CocoachinaItem
import scrapy
from scrapy.selector import Selector



class cocoachinaSpider(scrapy.Spider):
    name = "cocoachina"
    allowed_domains = ["cocoachina.com"]
    start_urls = [
        "http://www.cocoachina.com/news/",
    ]

    def parse(self, response):

        for clearfixSelector in response.xpath('//li[@class="clearfix"]'):
            dateSelector = clearfixSelector.xpath('h6[@class="float-l"]/text()').extract();
            for date in dateSelector:
               print "---------------- %s -------------" % date

            for sel in clearfixSelector.xpath('ul/li/a'):
                title = sel.xpath('text()').extract()[0]
                url = sel.xpath('@href').extract()[0]
                print title,url
