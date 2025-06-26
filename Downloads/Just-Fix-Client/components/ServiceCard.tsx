import React from "react";
import { MapPin, Clock, Star } from "lucide-react";

interface Service {
  imageUrl: string;
  title: string;
  description: string;
  location: string;
  availableTime: string;
  price: number;
  rating: number;
}

interface ServiceCardProps {
  service: Service;
}

const ServiceCard: React.FC<ServiceCardProps> = ({ service }) => {
  return (
    <div className="flex flex-col md:flex-row bg-white rounded-2xl shadow-md overflow-hidden hover:shadow-lg transition-all duration-300 w-full max-w-3xl">
      {/* Image Section */}
      <img
        src={service.imageUrl}
        alt={service.title}
        className="w-full md:w-1/3 h-48 md:h-auto object-cover"
      />

      {/* Content Section */}
      <div className="p-4 flex flex-col justify-between flex-1">
        <div>
          <h2 className="text-xl font-semibold">{service.title}</h2>
          <p className="text-sm text-gray-600 mt-1">{service.description}</p>

          <div className="mt-3 flex items-center text-sm text-gray-500">
            <MapPin className="w-4 h-4 mr-1" />
            {service.location}
          </div>

          <div className="mt-1 flex items-center text-sm text-gray-500">
            <Clock className="w-4 h-4 mr-1" />
            {service.availableTime}
          </div>
        </div>

        <div className="mt-4 flex flex-col md:flex-row md:items-center md:justify-between">
          <div className="flex items-center text-sm text-gray-700 mb-2 md:mb-0">
            <span className="font-semibold text-lg mr-2 text-blue-600">
              ৳{service.price}
            </span>
            <div className="flex items-center text-yellow-500">
              <Star className="w-4 h-4 mr-1 fill-yellow-400" />
              {service.rating}
            </div>
          </div>

          <button className="w-full md:w-auto bg-blue-600 hover:bg-blue-700 text-white text-sm py-2 px-4 rounded-xl transition">
            Book Now
          </button>
        </div>
      </div>
    </div>
  );
};

export default ServiceCard;
