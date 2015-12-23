# -*- coding: utf-8 -*-


from cocoachina.items import CocoachinaItem
import scrapy
from scrapy.selector import Selector
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors.sgml import SgmlLinkExtractor
from scrapy.contrib.linkextractors import LinkExtractor
from scrapy.http import Request



class cocoachinaSpider(scrapy.Spider):
    name = "cocoachina"
    allowed_domains = ["cocoachina.com"]
    start_urls = [
        "http://www.cocoachina.com/news/index.php?num=2",
    ]
    url = 'http://www.cocoachina.com/news/index.php?num='
    page = 2
    def parse(self, response):
        for clearfixSelector in response.xpath('//li[@class="clearfix"]'):
            dateSelector = clearfixSelector.xpath('h6[@class="float-l"]/text()').extract();
            for date in dateSelector:
               print "---------------- %s -------------" % date
            for sel in clearfixSelector.xpath('ul/li/a'):
                title = sel.xpath('text()').extract()[0]
                url = sel.xpath('@href').extract()[0]
                item = CocoachinaItem()
                item['title'] = title
                item['url'] = url
                print title,url                
                # yield item
            self.page = self.page + 1
            yield Request(self.url + '%s' % self.page,callback = self.parse)
