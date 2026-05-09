import { Body, Controller, Get, Post } from '@nestjs/common';
import { AppService } from './app.service';
import { CreateSensorReadingDto } from './dto/requests/create-sensor-reading.dto';

@Controller()
export class AppController {
  constructor(private readonly appService: AppService) { }

  @Get()
  getHello(): string {
    return this.appService.getHello();
  }

  @Post()
  create(@Body() body: CreateSensorReadingDto) {
    this.appService.create(body);
  }
}
