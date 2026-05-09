import { Injectable } from '@nestjs/common';
import { CreateSensorReadingDto } from './dto/requests/create-sensor-reading.dto';

@Injectable()
export class AppService {
  getHello(): string {
    console.log('Был запрос')
    return 'Hello World!!';
  }

  create(body: CreateSensorReadingDto) {
    console.log(body)
  }
}
